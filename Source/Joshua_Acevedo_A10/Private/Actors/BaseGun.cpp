// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseGun.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "../../Joshua_Acevedo_A10.h"

// Sets default values
ABaseGun::ABaseGun()
{
    PrimaryActorTick.bCanEverTick = false;
    SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("SkeletalMesh'/Game/END_Starter/Guns/Rifle/SK_Rifle.SK_Rifle'"));
    SkeletalMeshComponent->SetSkeletalMesh(SkeletalMeshAsset.Object);
    RootComponent = SkeletalMeshComponent;
    BulletClass = ABaseBullet::StaticClass();
    
    //Set SocketName, Location and Rotation
    SocketName = TEXT("MuzzleFlashSocket");
}

// Called when the game starts or when spawned
void ABaseGun::BeginPlay()
{
	Super::BeginPlay();
    parentPawn = Cast<APawn>(GetParentActor());
    if (parentPawn)
    {
        UE_LOG(Game, Warning, TEXT("Parent Pawn Casted!"));
    }
    else
    {
        UE_LOG(Game, Error, TEXT("We need a pawn to use this weapon."));
    }
	
}

void ABaseGun::Attack()
{
        FVector SpawnLocation = SkeletalMeshComponent->GetSocketLocation(SocketName);
        FRotator SpawnRotation = parentPawn->GetBaseAimRotation();
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = parentPawn;
        GetWorld()->SpawnActor<ABaseBullet>(BulletClass, SpawnLocation, SpawnRotation, SpawnParams);
}

// Called every frame
void ABaseGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

