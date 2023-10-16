// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExposeVariable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVariableDelegate, AActor*, Object);

UCLASS()
class JOSHUA_ACEVEDO_A10_API AExposeVariable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExposeVariable();
	void K2_DestroyActor() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//----------------------------------->  Variable Examples Start
	
	//Read Only
		/* Bool */ UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|ReadOnly") bool VisibleAnywhere = true;
		/* Byte */ UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadOnly") uint8 VisibleDefaultsOnly;
		/* Interger */ UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadOnly", AdvancedDisplay) int32 VisibleInstanceOnlyOdd;
		/* Interger 64 */ UPROPERTY(VisibleInstanceOnly, Category = "Variable|ReadOnly") int64 VisibleInstanceOnly;

	//Read Write
		/* Float */  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ReadWrite") float EditAnywhere;
		/* Name */ UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variable|ReadWrite", AdvancedDisplay) FName EditDefaultsOnlyOdd;
		/* String */ UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadWrite") FString EditDefaultsOnly;
		/* Text */ UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadWrite", AdvancedDisplay) FText EditInstanceOnlyOdd;
		/* Vector */ UPROPERTY(EditInstanceOnly, Category = "Variable|ReadWrite") FVector EditInstanceOnly;

		//----------------------------------->  Variable Examples End


		// Reference Class
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ClassReference") TSubclassOf<AActor> ClassType;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	//Naming The Variable
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Variable|Delegate");
	FVariableDelegate OnTestDelegate;

	UFUNCTION()
	void CallFunction(AActor *Object);
};
