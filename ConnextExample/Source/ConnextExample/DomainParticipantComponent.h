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

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ndds/ndds_cpp.h"

// Must be last include in file
#include "DomainParticipantComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDDS, Log, All);

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CONNEXTEXAMPLE_API UDomainParticipantComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    // Initialization method that must be called before other components reference an instance of
    // this component. QosProfilePathName must have the format "<QosLibraryName>::<QosProfileName>".
    UFUNCTION(BlueprintCallable, Category = "DDS", meta = (
        DisplayName = "Create DDS Participant",
        DefaultValue_DomainId = "0",
        DefaultValue_QosProfilePathName = "DEFAULT",
        DefaultValue_XMLQosFile = "USER_QOS_PROFILES.xml"
        ))
    void InitializeParticipant(const int32 DomainId, 
                               const FString& QosProfilePathName,
                               const FString& XMLQosFile);

    // Returns the participant for use by other components
    DDSDomainParticipant* GetParticipant() { return _participant; };

public:
    UDomainParticipantComponent();
	~UDomainParticipantComponent();

    // QosProfilePathName must have the format "<QosLibraryName>::<QosProfileName>".
    DDSDataWriter* CreateDataWriter(const FString& TopicName, const FString& TypeName, const FString& QosProfilePathName);
    // QosProfilePathName must have the format "<QosLibraryName>::<QosProfileName>".
    DDSDataReader* CreateDataReader(const FString& TopicName, const FString& TypeName, const FString& QosProfilePathName);

    static void StopGameSession(UObject* WorldContextObject);

protected:

    DDSTopic* GetOrCreateTopic(const FString& TopicName, const FString& TypeName);
    DDSDomainParticipant* _participant;
};
