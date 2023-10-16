// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WidgetHud.h"
#include "Components/ProgressBar.h"
#include "../../Joshua_Acevedo_A10.h"


UWidgetHud::UWidgetHud(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// The progress bar is not valid
	if (Health)
	{
		UE_LOG(Game, Warning, TEXT("Valid in the CTOR"));
		SetHealth(Ratio);
	}
}

void UWidgetHud::NativeOnInitialized()
{
	if (Health)
		UE_LOG(Game, Warning, TEXT("Valid in the NativeOnInitialized"));
}

void UWidgetHud::SetHealth(float _Ratio)
{
	Health->SetPercent(_Ratio);
}



