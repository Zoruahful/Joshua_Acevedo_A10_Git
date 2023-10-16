// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <SessionFrontend/Private/Models/SessionConsoleCategoryFilter.h>
#include "WidgetHud.generated.h"


/**
 *
 */
UCLASS()
class JOSHUA_ACEVEDO_A10_API UWidgetHud : public UUserWidget 
{
	GENERATED_BODY()

public:
	UWidgetHud(const FObjectInitializer& ObjectInitializer);
	void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable)
	void SetHealth(float _Ratio);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget));
	class UProgressBar* Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Vars")
	float Ratio;

private:

};
