// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "BMBossCharacter.generated.h"

UCLASS()
class UE_CPP_BOSSMODE_PRAC_API ABMBossCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABMBossCharacter();

	virtual float TakeDamage(float Damage, const struct FDamageEvent& DamagEvent, AController* EventInstigator,
	                         AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=AI)
	const float GetHealth();

	UPROPERTY(EditAnywhere, Category=Pawn)
	UBehaviorTree* BehaviorTree;

private:
	UPROPERTY()
	float Health;
};
