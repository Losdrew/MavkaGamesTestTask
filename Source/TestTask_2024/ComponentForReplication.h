// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "ComponentForReplication.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_2024_API UComponentForReplication : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
protected:

	virtual bool IsSupportedForNetworking() const override { return true; }
};
