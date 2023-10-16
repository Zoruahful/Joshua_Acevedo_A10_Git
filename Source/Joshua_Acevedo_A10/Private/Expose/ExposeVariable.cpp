// Fill out your copyright notice in the Description page of Project Settings.


#include "Expose/ExposeVariable.h"
#include "../../Joshua_Acevedo_A10.h"

// Sets default values
AExposeVariable::AExposeVariable() : VisibleInstanceOnlyOdd(3), EditAnywhere(3.2f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	OnTestDelegate.AddDynamic(this, &AExposeVariable::CallFunction);


}

void AExposeVariable::K2_DestroyActor() //----> Spawning an actor
{
	//5 of 7
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = nullptr;
	GetWorld()->SpawnActor<AActor>(ClassType, GetActorLocation(), GetActorRotation(), SpawnParams);
}

// Called when the game starts or when spawned
void AExposeVariable::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(Game, Error, TEXT("Actor's name is %s"), *GetName());
	UE_LOG(Game, Display, TEXT("int %d and float %f"), VisibleInstanceOnlyOdd, EditAnywhere);
	UE_LOG(Game, Warning, TEXT("Velocity is %s"), *GetVelocity().ToString());


	// ------->  Timer to destroy bullet
	FTimerHandle myHandle;
	GetWorld()->GetTimerManager().SetTimer(myHandle, this, &AExposeVariable::K2_DestroyActor, 3.0f); // ---> This sets timers

	OnTestDelegate.Broadcast(this);
}

// Called every frame
void AExposeVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExposeVariable::CallFunction(AActor *Object)
{
	UE_LOG(Game, Warning, TEXT("DELEGATE called this function"));
}


