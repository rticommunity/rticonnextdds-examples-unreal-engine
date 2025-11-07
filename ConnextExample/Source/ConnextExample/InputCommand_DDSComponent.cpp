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

#include "InputCommand_DDSComponent.h"

UInputCommand_DDSComponent::UInputCommand_DDSComponent() : _datawriter(NULL), _datareader(NULL)
{
    PrimaryComponentTick.bCanEverTick = true;
    UE_LOG(LogDDS, Error, TEXT("UInputCommand_DDSComponent Constructed"));
}

/*
 * This method must be called before WriteInputCommand() is invoked.
 *
 * It requires a Topic name, a Qos Profile path of format "<QosLibraryName>::<QosProfileName>"
 * as well as a reference to an instance of DomainParticipantComponent.
 */
void UInputCommand_DDSComponent::InitializeDataWriter(const FString& TopicName, 
                                                      const FString& QosProfilePath, 
                                                      UDomainParticipantComponent* DomainParticipantComponent)
{
    // In case the user clears these parameters in the Blueprint
    FString EffectiveQosProfilePath = QosProfilePath.IsEmpty() ? TEXT("DEFAULT") : QosProfilePath;

    const FString TypeName = "InputCommandType";

    // Register type if not registered
    if (DomainParticipantComponent->GetParticipant()->get_typecode(TCHAR_TO_ANSI(*TypeName)) == NULL) {
        InputCommandTypeTypeSupport::register_type(DomainParticipantComponent->GetParticipant());
        UE_LOG(LogDDS, Log, TEXT("UInputCommand_DDSComponent type \"%s\" registered"), *TypeName);
    }

    DDSDataWriter* writer = DomainParticipantComponent->CreateDataWriter(TopicName, TypeName, EffectiveQosProfilePath);

    _datawriter = InputCommandTypeDataWriter::narrow(writer);

    if (_datawriter == NULL) {
        UE_LOG(LogDDS, Error, TEXT("UInputCommand_DDSComponent failed to create DataWriter for Topic \"%s\""), *TopicName);
        UDomainParticipantComponent::StopGameSession(this);
    }
    else {
        UE_LOG(LogDDS, Log, TEXT("UInputCommand_DDSComponent created DataWriter for Topic \"%s\""), *TopicName);
    }
}

/*
 * This method must be called before ReadInputCommand() is invoked.
 *
 * It requires a Topic name, a Qos Profile path of format "<QosLibraryName>::<QosProfileName>"
 * as well as a reference to an instance of DomainParticipantComponent.
 */
void UInputCommand_DDSComponent::InitializeDataReader(const FString& TopicName, 
                                                      const FString& QosProfilePath, 
                                                      UDomainParticipantComponent* DomainParticipantComponent)
{
    // In case the user clears these parameters in the Blueprint
    FString EffectiveQosProfilePath = QosProfilePath.IsEmpty() ? TEXT("DEFAULT") : QosProfilePath;

    const FString TypeName = "InputCommandType";

    if (DomainParticipantComponent == NULL) {
        UE_LOG(LogDDS, Log, TEXT("UInputCommand_DDSComponent DomainParticipantComponent is not connected/set"));
        UDomainParticipantComponent::StopGameSession(this);
        return;
    }

    // Register type if not registered
    if (DomainParticipantComponent->GetParticipant()->get_typecode(TCHAR_TO_ANSI(*TypeName)) == NULL) {
        InputCommandTypeTypeSupport::register_type(DomainParticipantComponent->GetParticipant());
        UE_LOG(LogDDS, Log, TEXT("UInputCommand_DDSComponent registered \"%s\""), *TypeName);
    }

    DDSDataReader* reader = DomainParticipantComponent->CreateDataReader(TopicName, TypeName, EffectiveQosProfilePath);

    _datareader = InputCommandTypeDataReader::narrow(reader);

    if (_datareader == NULL) {
        UE_LOG(LogDDS, Error, TEXT("UInputCommand_DDSComponent failed to create DataReader for Topic \"%s\""), *TopicName);
        UDomainParticipantComponent::StopGameSession(this);
    }
    else {
        UE_LOG(LogDDS, Log, TEXT("UInputCommand_DDSComponent created DataReader for Topic \"%s\""), *TopicName);
    }
}


/*
 * When invoked, the input values of throttle, steering and brake will be copied into a InputCommandType
 * data structure which is then sent with a DDSDataWriter.
 */
void UInputCommand_DDSComponent::WriteInputCommand(float Throttle, float Steering, float Brake)
{
    InputCommandType inputCommand;

    inputCommand.throttle = Throttle;
    inputCommand.steering = Steering;
    inputCommand.brake = Brake;

    // Race condition here..._datawriter may not have been successfully created
    // but quiting game takes time...
    if (_datawriter) {
        _datawriter->write(inputCommand, DDS_HANDLE_NIL);
        UE_LOG(LogDDS, Log, TEXT("Published InputCommandType"));
    }

}


/*
 * When invoked, the last value received by the DDSDataReader will be copied into the output values 
 * of throttle, steering and brake.  Intermediate values are discarded.
 */
void UInputCommand_DDSComponent::ReadInputCommand(float& Throttle, float& Steering, float& Brake)
{
    InputCommandTypeSeq inputCommandSeq;

    if (_datareader) {

        DDS_SampleInfoSeq infoSeq;
        int32 length;

        // Possible that multiple commands have been received since last poll
        // Data is received in a sequence (variable-length array)
        if (_datareader->take(inputCommandSeq, infoSeq) == DDS_RETCODE_OK) {
            length = inputCommandSeq.length();

            // Only need to copy out the value of the last received command
            if (length > 0) {

                int32 lastIndex = length - 1;

                // Always need to check for data validity
                if (infoSeq[lastIndex].valid_data) {
                    Throttle = inputCommandSeq[lastIndex].throttle;
                    Steering = inputCommandSeq[lastIndex].steering;
                    Brake = inputCommandSeq[lastIndex].brake;
                    UE_LOG(LogDDS, Log, TEXT("Received InputCommand"));
                }
            }

            // Loaned storage for data/info is returned to the DataReader
            _datareader->return_loan(inputCommandSeq, infoSeq);
        }
    }
}

