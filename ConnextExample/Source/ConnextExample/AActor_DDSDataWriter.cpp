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

#include "AActor_DDSDataWriter.h"

UAActor_DDSDataWriter::UAActor_DDSDataWriter() : _datawriter(NULL)
{
    PrimaryComponentTick.bCanEverTick = true;
    UE_LOG(LogDDS, Error, TEXT("UAActor_DDSDataWriter Constructed"));
}


/*
 * This method must be called before WriteActorState() is invoked.
 * 
 * It requires a Topic name, a Qos Profile path of format "<QosLibraryName>::<QosProfileName>"
 * as well as a reference to an instance of DomainParticipantComponent.
 */
void UAActor_DDSDataWriter::InitializeDataWriter(const FString& TopicName, 
                                                 const FString& QosProfilePath, 
                                                 UDomainParticipantComponent* DomainParticipantComponent)
{
    // In case the user clears these parameters in the Blueprint
    FString EffectiveQosProfilePath = QosProfilePath.IsEmpty() ? TEXT("DEFAULT") : QosProfilePath;

    const FString TypeName = "AActorType";

    // Register type if not registered
    if (DomainParticipantComponent->GetParticipant()->get_typecode(TCHAR_TO_ANSI(*TypeName)) == NULL) {
        AActorTypeTypeSupport::register_type(DomainParticipantComponent->GetParticipant());
        UE_LOG(LogDDS, Log, TEXT("UAActor_DDSDataWriter type \"%s\" registered"), *TypeName);
    }
  
    DDSDataWriter* writer = DomainParticipantComponent->CreateDataWriter(TopicName, TypeName, EffectiveQosProfilePath);

    _datawriter = AActorTypeDataWriter::narrow(writer);

    if (_datawriter == NULL) {
        UE_LOG(LogDDS, Error, TEXT("UAActor_DDSDataWriter failed to create DataWriter for Topic \"%s\""), *TopicName);
        UDomainParticipantComponent::StopGameSession(this);
    }
    else {
        UE_LOG(LogDDS, Log, TEXT("UAActor_DDSDataWriter created DataWriter for Topic \"%s\""), *TopicName);
    }
}

/*
 * When invoked, the state of the AActor that "owns" the component will be copied into a AActorType 
 * data structure which is then sent with a DDSDataWriter.
 */
void UAActor_DDSDataWriter::WriteActorState()
{
    AActorType actorState;

    AActor* Owner = GetOwner();
    if (!Owner)
    {
        UE_LOG(LogDDS, Warning, TEXT("AActor_DDSDataWriter has no owner"));
        return;
    }

    // Get actor transform
    FVector Location = Owner->GetActorLocation();
    FRotator Rotation = Owner->GetActorRotation();

    // Try to get vehicle velocity
    FVector Velocity(0, 0, 0);
    UPrimitiveComponent* RootComp = Cast<UPrimitiveComponent>(Owner->GetRootComponent());
    Velocity = RootComp->GetComponentVelocity();

    // Prepare DDS message
    actorState.pos.x = Location.X;
    actorState.pos.y = Location.Y;
    actorState.pos.z = Location.Z;
    actorState.vel.x = Velocity.X;
    actorState.vel.y = Velocity.Y;
    actorState.vel.z = Velocity.Z;
    actorState.rot.roll = Rotation.Roll;
    actorState.rot.pitch = Rotation.Pitch;
    actorState.rot.yaw = Rotation.Yaw;

    // Race condition here..._datawriter may not have been successfully created
    // but quiting game takes time...
    if (_datawriter) {
        _datawriter->write(actorState, DDS_HANDLE_NIL);
        UE_LOG(LogDDS, Log, TEXT("Published DDS Vehicle State for %s [pos %s, vel %s]"),
            *Owner->GetName(), *Location.ToString(), *Velocity.ToString());
    }
}

