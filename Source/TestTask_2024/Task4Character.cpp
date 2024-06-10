// RedRuins Softworks (c)


#include "Task4Character.h"
#include "ObjectForReplication.h"
#include "ComponentForReplication.h"
#include "Net/UnrealNetwork.h"
#include "Engine/ActorChannel.h"

ATask4Character::ATask4Character()
	: ObjectForReplication(nullptr), DynamicComponentForReplication(nullptr), SkeletalMesh(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicateUsingRegisteredSubObjectList = true;
}

void ATask4Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ObjectForReplication);
	DOREPLIFETIME(ThisClass, DynamicComponentForReplication);
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

void ATask4Character::CreateDynamicComponent()
{
	if (HasAuthority())
	{
		if (DynamicComponentForReplication != nullptr)
		{
			RemoveReplicatedSubObject(DynamicComponentForReplication);
			DynamicComponentForReplication->UninitializeComponent();
		}
	
		DynamicComponentForReplication = NewObject<UComponentForReplication>(this);
		DynamicComponentForReplication->SetupAttachment(RootComponent);
		DynamicComponentForReplication->RegisterComponent();
		AddReplicatedSubObject(DynamicComponentForReplication);
		
		OnRep_DynamicComponentForReplication();
	}
}

void ATask4Character::OnRep_ObjectForReplication()
{
	ObjectForReplication->PrintValues();
}

void ATask4Character::OnRep_DynamicComponentForReplication()
{
	if (DynamicComponentForReplication != nullptr)
	{
		DynamicComponentForReplication->SetSkeletalMesh(SkeletalMesh);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, DynamicComponentForReplication.GetPath());
	}
}