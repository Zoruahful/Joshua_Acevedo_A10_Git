// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/BaseCharacterEventGraph.h"

void UBaseCharacterEventGraph::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	APawn *pawn = TryGetPawnOwner();
	if(nullptr != pawn)
	{
		// Is Valid
		speed = pawn->GetVelocity().Size();
		direction = AnimInstance->CalculateDirection(pawn->GetVelocity(), pawn->GetActorRotation());
	}
	else
	{
		// Is NOT Valid

	}
}


