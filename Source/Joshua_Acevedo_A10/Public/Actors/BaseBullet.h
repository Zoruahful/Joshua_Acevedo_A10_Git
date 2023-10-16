// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseBullet.generated.h"

UCLASS()
class JOSHUA_ACEVEDO_A10_API ABaseBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) 
	class USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) 
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) 
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Variable|Vars") 
	FVector Scale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Vars") 
	float TimeToDestroy;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION() 
	void OnBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void DestroyTimer();
};
