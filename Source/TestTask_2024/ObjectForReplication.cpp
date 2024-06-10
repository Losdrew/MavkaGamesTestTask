// RedRuins Softworks (c)


#include "ObjectForReplication.h"
#include "Net/UnrealNetwork.h"

void UObjectForReplication::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ThisClass, ReplicatedValues);
}

void UObjectForReplication::GenerateRandomValues()
{
    ReplicatedValues.Value1 = FMath::RandBool();
    ReplicatedValues.Value2 = FMath::RandRange(0.f, 100.f);
    ReplicatedValues.Value3 = FMath::RandRange(0, 100);

    OnRep_ReplicatedValues();
}

void UObjectForReplication::OnRep_ReplicatedValues()
{
    PrintValues();
}

void UObjectForReplication::PrintValues()
{
    if (AActor* Actor = Cast<AActor>(GetOuter()))
    {
        int32 Key = Actor->GetUniqueID();
        FColor Color = Actor->HasAuthority() ? FColor::Purple : FColor::Orange;
        const wchar_t* RoleText = Actor->HasAuthority() ? TEXT("Server") : TEXT("Client");
        const wchar_t* Value1Text = ReplicatedValues.Value1 ? TEXT("true") : TEXT("false");

        GEngine->AddOnScreenDebugMessage(Key, 999.f, Color, FString::Printf(TEXT("%s: %s    %.1f    %d"), RoleText, Value1Text, ReplicatedValues.Value2, ReplicatedValues.Value3));
    }
}