// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectForReplication.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedValues
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool Value1 = true;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Value2 = 55.f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 Value3 = 21;
};

/**
 * 
 */
UCLASS(Blueprintable)
class TESTTASK_2024_API UObjectForReplication : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void PrintValues();

	UFUNCTION(BlueprintCallable)
	void GenerateRandomValues();

protected:

	virtual bool IsSupportedForNetworking() const override { return true; }
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ReplicatedValues();

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, ReplicatedUsing = OnRep_ReplicatedValues)
	FReplicatedValues ReplicatedValues;
};
