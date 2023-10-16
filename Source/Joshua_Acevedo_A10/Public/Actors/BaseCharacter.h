// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseBullet.h"
#include "BaseGun.h"
#include "BaseCharacter.generated.h"


UCLASS(ABSTRACT)
class JOSHUA_ACEVEDO_A10_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Vars
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite) 
	UChildActorComponent* WeaponChildActorComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ClassReference") 
	TSubclassOf<ABaseGun> WeaponClass;

	UPROPERTY(BlueprintReadOnly, Category = "Variable|Vars") 
	class ABaseGun* CurrentWeapon;

	UPROPERTY(BlueprintReadOnly, Category = "Variable|Vars") 
	class UAnimInstance* AnimBP;

	UPROPERTY(BlueprintReadOnly, Category = "Variable|Vars") 
	class UAnimSequenceBase* Asset;

	ABaseGun* BaseGun;
	UAnimInstance* AnimInstance;


	//Function
	UFUNCTION(BlueprintCallable) 
	void CharacterAttack();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
