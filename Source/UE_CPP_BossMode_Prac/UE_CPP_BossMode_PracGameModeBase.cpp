// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE_CPP_BossMode_PracGameModeBase.h"

AUE_CPP_BossMode_PracGameModeBase::AUE_CPP_BossMode_PracGameModeBase(): Super()
{
	ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FPCharacter"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
