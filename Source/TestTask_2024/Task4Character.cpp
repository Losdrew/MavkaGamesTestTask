// RedRuins Softworks (c)


#include "Task4Character.h"
#include "ObjectForReplication.h"
#include "Net/UnrealNetwork.h"
#include "Engine/ActorChannel.h"

ATask4Character::ATask4Character()
	: ObjectForReplication(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicateUsingRegisteredSubObjectList = true;
}

void ATask4Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ObjectForReplication);
}

bool ATask4Character::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool bWroteSomething = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);
         
	if (IsValid(ObjectForReplication))
	{
		bWroteSomething |= Channel->ReplicateSubobject(ObjectForReplication, *Bunch, *RepFlags);
	}
			
    return bWroteSomething;
}

void ATask4Character::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		ObjectForReplication = NewObject<UObjectForReplication>(this);
		AddReplicatedSubObject(ObjectForReplication);
		OnRep_ObjectForReplication();
	}
}

void ATask4Character::OnRep_ObjectForReplication()
{
	ObjectForReplication->PrintValues();
}
