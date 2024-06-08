// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_1.generated.h"

class UDA_2;

USTRUCT(BlueprintType)
struct FTestStructure 
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
    UDA_2* DataAsset2;

    UPROPERTY(EditDefaultsOnly)
    FName Name;    
    
    UPROPERTY(EditDefaultsOnly)
    UTexture* Texture;    
    
    UPROPERTY(EditDefaultsOnly)
    FVector Vector;
};

/**
 * 
 */
UCLASS(BlueprintType)
class TESTTASK_2024_API UDA_1 : public UDataAsset
{
	GENERATED_BODY()
	
    UPROPERTY(EditDefaultsOnly)
    FTestStructure Structure;
};
