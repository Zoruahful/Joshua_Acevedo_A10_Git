// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExposeFunction.generated.h"

UCLASS()
class JOSHUA_ACEVEDO_A10_API AExposeFunction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExposeFunction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable) void BlueprintCallable();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void BlueprintImplementableEvent();

	// Call this one to also get to the Blueprint
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable) void BlueprintNativeEvent(); 
	
	//All C++ classes use this to overide not BlueprintNativeEvent();
	virtual void BlueprintNativeEvent_Implementation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
