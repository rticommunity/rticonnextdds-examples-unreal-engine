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
#include "AActor_DDSDataWriter.generated.h"

/**
 * This component is used to publish the "state" of the AActor object into which the component is
 * inserted (usually, the Blueprint in which the component is added).
 * 
 * The "state" consists of the AActor's location, velocity and attitude (aka rotation).
 * 
 * Invoking WriteActorState() will publish the data as a DDS sample for the Topic created during
 * initialization.
 * 
 * When/why the write method is invoked is up to the user...it can be done periodically by a tick event or 
 * through some user logic triggered on state change.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CONNEXTEXAMPLE_API UAActor_DDSDataWriter : public UActorComponent
{
	GENERATED_BODY()
    
    UAActor_DDSDataWriter();

public:
    // Initialization method that needs to be called before WriteActorState is invoked.
    UFUNCTION(BlueprintCallable, Category = "DDS", meta = (
        DisplayName = "Create DDS DataWriter",
        DefaultValue_QosProfilePath = "DEFAULT"))
    void InitializeDataWriter(const FString& TopicName, 
                              const FString& QosProfilePath, 
                              UDomainParticipantComponent* DomainParticipantComponent);

    // Blueprint-callable function to write data with DDS.
    UFUNCTION(BlueprintCallable, Category = "DDS")
    void WriteActorState();

protected:
    AActorTypeDataWriter* _datawriter;

};
