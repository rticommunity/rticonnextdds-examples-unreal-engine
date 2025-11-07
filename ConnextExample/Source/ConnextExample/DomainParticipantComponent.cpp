/*
 * (c) 2025 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
 *
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the software solely for use with RTI Connext DDS.  Licensee may
 * redistribute copies of the software provided that all such copies are
 * subject to this license. The software is provided "as is", with no warranty
 * of any type, including any warranty for fitness for any purpose. RTI is
 * under no obligation to maintain or support the software.  RTI shall not be
 * liable for any incidental or consequential damages arising out of the use or
 * inability to use the software.
 */

#include "DomainParticipantComponent.h"

#include "Engine/Engine.h" // For GEngine->AddOnScreenDebugMessage
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

DEFINE_LOG_CATEGORY(LogDDS);

/*
 *  Redirect the Connext logging to the Unreal Engine logger.
 */
class UELoggerDevice : public NDDSConfigLoggerDevice {
public:
    UELoggerDevice() {
    }
    ~UELoggerDevice() {
    }
    virtual void write(const NDDS_Config_LogMessage* message) {

        switch (message->level)
        {
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_DEBUG:
            UE_LOG(LogDDS, Verbose, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_STATUS_LOCAL:
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_STATUS_REMOTE:
            UE_LOG(LogDDS, Log, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_WARNING:
            UE_LOG(LogDDS, Warning, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_ERROR:
            UE_LOG(LogDDS, Error, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        case NDDS_Config_LogLevel::NDDS_CONFIG_LOG_LEVEL_FATAL_ERROR:
            UE_LOG(LogDDS, Fatal, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        default:
            UE_LOG(LogDDS, Log, TEXT("[DDS] %s"), UTF8_TO_TCHAR(message->text));
            break;
        }

    }
};

static UELoggerDevice _ddsLogger;


/*
 *  Used to stop an application running in PIE without exiting the Unreal Engine IDE.
 */
void UDomainParticipantComponent::StopGameSession(UObject* WorldContextObject)
{
    if (!WorldContextObject)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession failed: WorldContextObject is null"));
        return;
    }

    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession failed: could not resolve world"));
        return;
    }

    // Only trigger in PIE or game world
    if (World->WorldType != EWorldType::PIE && World->WorldType != EWorldType::Game)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession skipped: not PIE/Game world"));
        return;
    }

    // Get first player controller
    APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
    if (!PC)
    {
        UE_LOG(LogTemp, Warning, TEXT("StopGameSession failed: no player controller found"));
        return;
    }

    // Defer quitting slightly to ensure PIE world is fully ready
    FTimerHandle TimerHandle;
    World->GetTimerManager().SetTimer(TimerHandle, [World, PC]()
        {
            UE_LOG(LogTemp, Log, TEXT("Quitting game now"));
            UKismetSystemLibrary::QuitGame(World, PC, EQuitPreference::Quit, false);
        }, 0.01f, false);   // 0.01s
}


UDomainParticipantComponent::UDomainParticipantComponent() : _participant(NULL)
{
    NDDSConfigLogger* ddsLogger;
    ddsLogger = NDDSConfigLogger::get_instance();

    if (!ddsLogger->set_output_device(&_ddsLogger)) {
        UE_LOG(LogDDS, Error, TEXT("*** UDomainParticipantComponent could not set logger to UE_LOG"));
    }
}

UDomainParticipantComponent::~UDomainParticipantComponent()
{
    if (_participant != NULL) {
        _participant->delete_contained_entities();
        DDSTheParticipantFactory->delete_participant(_participant);
        _participant = NULL;
    }
}

/*
 *  Initialization method that must be called before other components reference an instance of
 *  this component. QosProfilePathName must have the format "<QosLibraryName>::<QosProfileName>"
 */
void UDomainParticipantComponent::InitializeParticipant(const int32 DomainId, const FString& QosProfilePathName, const FString& XMLQosFile)
{
    // In case the user clears these parameters in the Blueprint, have some default values
    FString EffectiveQosProfilePathName = QosProfilePathName.IsEmpty() ? TEXT("DEFAULT") : QosProfilePathName;
    FString EffectiveXMLQosFile = XMLQosFile.IsEmpty() ? TEXT("USER_QOS_PROFILES.xml") : XMLQosFile;

    // Configure factory to load XMLQosFile if is not the default
    if (!EffectiveXMLQosFile.Equals(TEXT("USER_QOS_PROFILES.xml"))) {
        DDS_DomainParticipantFactoryQos factoryQos;
        DDSTheParticipantFactory->get_qos(factoryQos);

        /* The XML QoS File is expected to located in the root of the project directory */
        FString xmlFile = FPaths::Combine(FPaths::ProjectDir(), EffectiveXMLQosFile);
        factoryQos.profile.url_profile.ensure_length(1, 1);
        factoryQos.profile.url_profile[0] = DDS_String_dup(TCHAR_TO_ANSI(*xmlFile));

        DDSTheParticipantFactory->set_qos(factoryQos);
    }

    DDS_DomainParticipantQos participant_qos;
    
    // The "default" participant qos value may be modified by loading the XML Qos file.
    if (DDSTheParticipantFactory->get_default_participant_qos(participant_qos) != DDS_RETCODE_OK) {
        UE_LOG(LogDDS, Warning, TEXT("UDomainParticipantComponent failed to get default DomainParticipantQos"));

        // Use hardcoded values if couldn't initialize otherwise
        participant_qos = DDS_PARTICIPANT_QOS_DEFAULT;
    }

    // Load the qos from the profile if user configured a non-DEFAULT profile
    if (!EffectiveQosProfilePathName.Equals(TEXT("DEFAULT"))) {
        FString LibraryName;
        FString QosProfileName;

        EffectiveQosProfilePathName.Split(TEXT("::"), &LibraryName, &QosProfileName);

        if (DDSTheParticipantFactory->get_participant_qos_from_profile(participant_qos, TCHAR_TO_ANSI(*LibraryName),
                                                                       TCHAR_TO_ANSI(*QosProfileName))
            != DDS_RETCODE_OK) {
            UE_LOG(LogDDS, Warning, TEXT("UDomainParticipantComponent failed to get DomainParticipantQos for QosProfile \"%s\""),
                *EffectiveQosProfilePathName);

            // This is a hard error
            StopGameSession(this);
        }
    }

    _participant = DDSTheParticipantFactory->create_participant(DomainId, participant_qos, NULL, DDS_STATUS_MASK_NONE);

    if (_participant == NULL) {
        UE_LOG(LogDDS, Error, TEXT("UDomainParticipantComponent failed to create DomainParticipant"));
        StopGameSession(this);
    }
    else {
        UE_LOG(LogDDS, Log, TEXT("UDomainParticipantComponent created DomainParticipant"));
    }
}

/* 
 * Utility to get a DDSTopic for a given topic name and topic type.
 */
DDSTopic* UDomainParticipantComponent::GetOrCreateTopic(const FString& TopicName, const FString& TypeName)
{
    DDSTopic* topic = (DDSTopic *)_participant->lookup_topicdescription(TCHAR_TO_ANSI(*TopicName));

    if (topic == NULL) {
        topic = _participant->create_topic(TCHAR_TO_ANSI(*TopicName), TCHAR_TO_ANSI(*TypeName), DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

        if (topic == NULL) {
            UE_LOG(LogDDS, Error, TEXT("UDomainParticipantComponent failed to create Topic \"%s\" for type \"%s\" "), *TopicName, *TypeName);
            return NULL;
        }

        UE_LOG(LogDDS, Log, TEXT("UDomainParticipantComponent created Topic \"%s\""), *TopicName);
    }

    return topic;
}

/*
 * Utility method for other components to create a DDSDataWriter for a given topic name, topic type and QoS profile.
 */
DDSDataWriter* UDomainParticipantComponent::CreateDataWriter(const FString& TopicName, const FString& TypeName, 
    const FString& QosProfilePathName)
{
    DDSTopic* topic = GetOrCreateTopic(TopicName, TypeName);

    // If could not get or create topic, this is a problem
    if (topic == NULL) {
        return NULL;
    }

    FString LibraryName;
    FString QosProfileName;

    QosProfilePathName.Split(TEXT("::"), &LibraryName, &QosProfileName);

    // Using builtin/implicit DDSPublisher
    DDSDataWriter *writer = _participant->create_datawriter_with_profile(topic, 
        TCHAR_TO_ANSI(*LibraryName), TCHAR_TO_ANSI(*QosProfileName),
        NULL, DDS_STATUS_MASK_NONE);

    if (writer == NULL) {
        UE_LOG(LogDDS, Error, TEXT("UDomainParticipantComponent failed to create DataWriter for Topic \"%s\""), *TopicName);
        return NULL;
    }

    UE_LOG(LogDDS, Log, TEXT("UDomainParticipantComponent created DataWriter for Topic \"%s\""), *TopicName);

    return writer;
}

/*
 * Utility method for other components to create a DDSDataReader for a given topic name, topic type and QoS profile.
 */
DDSDataReader* UDomainParticipantComponent::CreateDataReader(const FString& TopicName, const FString& TypeName, 
    const FString& QosProfilePathName)
{
    DDSTopic* topic = GetOrCreateTopic(TopicName, TypeName);

    // If could not get or create topic, this is a problem
    if (topic == NULL) {
        return NULL;
    }

    FString LibraryName;
    FString QosProfileName;

    QosProfilePathName.Split(TEXT("::"), &LibraryName, &QosProfileName);

    // Using builtin/implicit DDSPublisher
    DDSDataReader* reader = _participant->create_datareader_with_profile(topic,
        TCHAR_TO_ANSI(*LibraryName), TCHAR_TO_ANSI(*QosProfileName),
        NULL, DDS_STATUS_MASK_NONE);

    if (reader == NULL) {
        UE_LOG(LogDDS, Error, TEXT("UDomainParticipantComponent failed to create DataReader for Topic \"%s\""), *TopicName);
        return NULL;
    }

    UE_LOG(LogDDS, Log, TEXT("UDomainParticipantComponent created DataReader for Topic \"%s\""), *TopicName);

    return reader;
}


