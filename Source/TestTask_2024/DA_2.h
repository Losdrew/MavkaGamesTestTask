// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_2.generated.h"

class UDA_1;

UENUM(BlueprintType)
enum class ETestEnumeration : uint8
{
	value_true	UMETA(DisplayName = "Value True"),
	value_false UMETA(DisplayName = "Value False"),
	value_n		UMETA(DisplayName = "Value N")
};

/**
 * 
 */
UCLASS(BlueprintType)
class TESTTASK_2024_API UDA_2 : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	ETestEnumeration Enumeration;
	
	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "Enumeration == ETestEnumeration::value_true", EditConditionHides))
	TObjectPtr<UDA_1> DataAsset1;
};
