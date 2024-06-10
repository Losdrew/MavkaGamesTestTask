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
