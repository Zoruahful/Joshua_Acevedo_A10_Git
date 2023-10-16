// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "../../Joshua_Acevedo_A10.h"

//--------- Reference
//Roll = X
//Pitch = Y
//Yaw = Z


ABasePlayer::ABasePlayer()
{
	// Skele Mesh
	MeshComponent = GetMesh();
	MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	MeshComponent->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	//Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeLocation(FVector(0.f, 80.f, 90.f));
	SpringArm->TargetArmLength = 210.f;

	//Camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArm);
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Player Turn
	PlayerInputComponent->BindAxis("TurnTo", this, &ABasePlayer::AddControllerYawInput);//W
	PlayerInputComponent->BindAxis("LookUp", this, &ABasePlayer::AddControllerPitchInput);

	//Player Move
	PlayerInputComponent->BindAxis("Forward", this, &ABasePlayer::InputAxisForward);//W
	PlayerInputComponent->BindAxis("Right", this, &ABasePlayer::InputAxisRight);//W

	//Player Shoot
	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &ABasePlayer::CallOnMouseClick);
	if (PlayerController)
	{
		HUDWidget = CreateWidget<UWidgetHud>(PlayerController, WidgetClass, TEXT("Health"));
		HUDWidget->AddToViewport();

	}
	else
	{
		UE_LOG(Game, Error, TEXT("Need A Player Controller"));
		Destroy();
	}


}

void ABasePlayer::InputAxisForward(float value)
{
	AddMovementInput(FRotator(0.f, GetControlRotation().Yaw, 0.f).Vector(), value);
}

void ABasePlayer::InputAxisRight(float value)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y), value);
}

void ABasePlayer::CallOnMouseClick()
{
	ABaseCharacter::CharacterAttack();
	UE_LOG(Game, Warning, TEXT("Left Mouse Click was pressed"));
}

