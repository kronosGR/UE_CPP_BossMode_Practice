// Fill out your copyright notice in the Description page of Project Settings.


#include "BMHUD.h"

#include "Engine/Canvas.h"

ABMHUD::ABMHUD()
{
	ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(
		TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));

	CrosshairTex = CrosshairTexObj.Object;
}

void ABMHUD::DrawHUD()
{
	const FVector2d Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5);
	const FVector2d CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5f)),
	                                      (Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));

	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode=SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}
