// Fill out your copyright notice in the Description page of Project Settings.


#include "Expose/ExposeDefaultPawn.h"
#include "GameFramework/PlayerInput.h"
#include "../../Joshua_Acevedo_A10.h"

// Sets default values
AExposeDefaultPawn::AExposeDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExposeDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	AActor *Actor = this;
	APawn* Pawn = Cast<APawn>(Actor);
	if (Pawn)
		UE_LOG(Game, Log, TEXT("We Are good"));
	
}

// Called every frame
void AExposeDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AExposeDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	// This is not needed to be exported FYI Only ------> Allow me to understand to make the gun shoot
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping(FName("SpaceBar"), EKeys::SpaceBar));
	//End Example
	PlayerInputComponent->BindAction("SpaceBar", EInputEvent::IE_Pressed, this, &AExposeDefaultPawn::CallOnSpacePressed);
}

void AExposeDefaultPawn::CallOnSpacePressed()
{
	UE_LOG(Game, Warning, TEXT("SpaceBar was pressed"))
}

