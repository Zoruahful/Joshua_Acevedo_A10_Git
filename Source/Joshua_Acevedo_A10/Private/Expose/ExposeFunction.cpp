// Fill out your copyright notice in the Description page of Project Settings.


#include "Expose/ExposeFunction.h"
#include "../../Joshua_Acevedo_A10.h"

// Sets default values
AExposeFunction::AExposeFunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BlueprintImplementableEvent();
	BlueprintNativeEvent_Implementation();

}

// Called when the game starts or when spawned
void AExposeFunction::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExposeFunction::BlueprintCallable()
{
	UE_LOG(Game, Error, TEXT("Blueprint Callable"));
}

void AExposeFunction::BlueprintNativeEvent_Implementation()
{
	UE_LOG(Game, Warning, TEXT("Blueprint Native Event"));
}

// Called every frame
void AExposeFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

