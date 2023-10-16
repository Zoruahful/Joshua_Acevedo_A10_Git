// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFloatEvent, float*, amount);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JOSHUA_ACEVEDO_A10_API UBaseHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Variable|Delegate");
	FFloatEvent OnHurt;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Variable|Delegate");
	FFloatEvent OnDead;

	UFUNCTION()
	void CallOnHurt(float* amount);

	UFUNCTION()
	void CallOnDead(float* amount);
};
