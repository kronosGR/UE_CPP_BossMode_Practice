// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BMHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_BOSSMODE_PRAC_API ABMHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABMHUD();

	virtual void DrawHUD() override;

private:
	UTexture2D* CrosshairTex;
};
