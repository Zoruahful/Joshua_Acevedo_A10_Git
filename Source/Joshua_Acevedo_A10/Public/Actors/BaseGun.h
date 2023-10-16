// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseBullet.h"
#include "BaseGun.generated.h"


UCLASS()
class JOSHUA_ACEVEDO_A10_API ABaseGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Vars & Class Reference
	UPROPERTY(VisibleAnywhere) USkeletalMeshComponent* SkeletalMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|Vars") 
	APawn* parentPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ClassReference") 
	TSubclassOf<ABaseBullet> BulletClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Vars") 
	FName SocketName;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Function
	UFUNCTION(BlueprintCallable, Category = "Custom Function") 
	void Attack();
};
