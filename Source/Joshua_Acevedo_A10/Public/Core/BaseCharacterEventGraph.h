// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseCharacterEventGraph.generated.h"

/**
 * 
 */
UCLASS()
class JOSHUA_ACEVEDO_A10_API UBaseCharacterEventGraph : public UAnimInstance
{
	GENERATED_BODY()
public:
	void NativeUpdateAnimation(float DeltaSeconds) override;
protected:
	UAnimInstance* AnimInstance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float speed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float direction;
};
