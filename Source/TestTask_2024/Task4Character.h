// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Task4Character.generated.h"

class UObjectForReplication;
class UComponentForReplication;

UCLASS()
class TESTTASK_2024_API ATask4Character : public ACharacter
{
	GENERATED_BODY()

public:

	ATask4Character();

	UFUNCTION(BlueprintCallable)
	void CreateDynamicComponent();

protected:

	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ObjectForReplication();

	UFUNCTION()
	void OnRep_DynamicComponentForReplication();

protected:

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ObjectForReplication)
	TObjectPtr<UObjectForReplication> ObjectForReplication;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DynamicComponentForReplication)
	TObjectPtr<UComponentForReplication> DynamicComponentForReplication;

private:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USkeletalMesh> SkeletalMesh;
};
