// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "../Widgets/WidgetHud.h"
#include "BasePlayer.generated.h"

UCLASS()
class JOSHUA_ACEVEDO_A10_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABasePlayer();
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);


protected:

	//Skele Mesh
	UPROPERTY(VisibleAnywhere) 
	class USkeletalMeshComponent* MeshComponent;

	//Spring Arm
	UPROPERTY(EditAnywhere) 
	class USpringArmComponent* SpringArm;

	// Camera
	UPROPERTY(EditAnywhere) 
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|Vars")
	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidgetHud> WidgetClass;

	UPROPERTY(BlueprintReadOnly, Category = "Variable|Vars")
	class UWidgetHud* HUDWidget;


private:
	void InputAxisForward(float value);
	void InputAxisRight(float value);
	void CallOnMouseClick();
};
