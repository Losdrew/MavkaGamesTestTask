// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Task4Character.generated.h"

class UObjectForReplication;

UCLASS()
class TESTTASK_2024_API ATask4Character : public ACharacter
{
	GENERATED_BODY()

public:

	ATask4Character();

protected:

	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ObjectForReplication();

protected:

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ObjectForReplication)
	TObjectPtr<UObjectForReplication> ObjectForReplication;
};
