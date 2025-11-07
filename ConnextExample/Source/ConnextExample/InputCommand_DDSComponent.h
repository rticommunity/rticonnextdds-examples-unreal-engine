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
#include "Components/ActorComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"

#include "ndds/ndds_cpp.h"
#include "UnrealBasicDDSTypes.h"
#include "UnrealBasicDDSTypesSupport.h"

#include "DomainParticipantComponent.h"

// Must be last include in file
#include "InputCommand_DDSComponent.generated.h"

/**
 * This component can be used to publish or subscribe to Topics of
 * type "InputCommandType" with DDS.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CONNEXTEXAMPLE_API UInputCommand_DDSComponent : public UActorComponent
{
	GENERATED_BODY()
    
    UInputCommand_DDSComponent();

public:
    // Initialization method that needs to be called before WriteInputCommand is invoked.
    UFUNCTION(BlueprintCallable, Category = "DDS", meta = (
        DisplayName = "Create DDS DataWriter",
        DefaultValue_QosProfilePath = "DEFAULT"))
    void InitializeDataWriter(const FString& TopicName, 
                              const FString& QosProfilePath, 
                              UDomainParticipantComponent* DomainParticipantComponent);

    // Initialization method that needs to be called before ReadInputCommand is invoked.
    UFUNCTION(BlueprintCallable, Category = "DDS", meta = (
        DisplayName = "Create DDS DataReader",
        DefaultValue_QosProfilePath = "DEFAULT"))
    void InitializeDataReader(const FString& TopicName, 
                              const FString& QosProfilePath, 
                              UDomainParticipantComponent* DomainParticipantComponent);

    // Blueprint-callable function to write data
    UFUNCTION(BlueprintCallable, Category = "DDS")
    void WriteInputCommand(float Throttle, float Steering, float Brake);

    // Blueprint-callable function to poll for data, only the last value received
    // is copied to output.
    UFUNCTION(BlueprintCallable, Category = "DDS")
    void ReadInputCommand(float& Throttle, float& Steering, float& Brake);

protected:
    InputCommandTypeDataWriter* _datawriter;
    InputCommandTypeDataReader* _datareader;
};
