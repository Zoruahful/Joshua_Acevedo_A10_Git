// Fill out your copyright notice in the Description page of Project Settings.
#include "Actors/BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "../../Joshua_Acevedo_A10.h"



// Sets default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->SetRelativeRotation(FRotator(0.0f,-90.0f,0.0f));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));

	// Weapon Child Actor Component
	WeaponChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponChildActorComponent"));
	FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, true);
	WeaponChildActorComponent->AttachToComponent(GetMesh(), AttachmentTransformRules, TEXT("WeaponPlacement"));
	Asset = LoadObject<UAnimSequenceBase>(nullptr, TEXT("/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	WeaponChildActorComponent->SetChildActorClass(WeaponClass);
	BaseGun = Cast<ABaseGun>(WeaponChildActorComponent->GetChildActor());
	if (BaseGun)
	{
		CurrentWeapon = BaseGun;
		UE_LOG(Game, Warning, TEXT("Weapon Casted!"));
		AnimInstance = Cast<UAnimInstance>(GetMesh()->GetAnimInstance());
		if (AnimInstance)
		{
			AnimBP = AnimInstance;
			UE_LOG(Game, Warning, TEXT("Animation Casted!"));
		}
		else
		{
			UE_LOG(Game, Error, TEXT("We have to set our animation to the right type"));
		}
	}
	else
	{
		UE_LOG(Game, Error, TEXT("There is no weapon will crash"));
		K2_DestroyActor();
	}
	
}

void ABaseCharacter::CharacterAttack()
{
	CurrentWeapon->Attack();
	if (Asset)
	{
		AnimBP->PlaySlotAnimation(Asset, TEXT("Action"));
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Asset is not Loaded!"));
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

