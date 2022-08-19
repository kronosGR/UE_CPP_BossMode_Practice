// Fill out your copyright notice in the Description page of Project Settings.


#include "BMBossCharacter.h"

#include "GameFramework/PawnMovementComponent.h"

// Sets default values
ABMBossCharacter::ABMBossCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.f;

	GetMovementComponent()->NavAgentProps.AgentHeight = 320.f;
	GetMovementComponent()->NavAgentProps.AgentRadius = 160.f;
}

float ABMBossCharacter::TakeDamage(float Damage, const FDamageEvent& DamagEvent, AController* EventInstigator,
                                   AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamagEvent, EventInstigator, DamageCauser);

	Health -= Damage;

	return Damage;
}

const float ABMBossCharacter::GetHealth()
{
	return Health;
}
