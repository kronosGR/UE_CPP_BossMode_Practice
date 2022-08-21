// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BMAIController.h"
#include "BMBossCharacter.h"
#include "BehaviorTree/BTService.h"
#include "BMAgroCheck.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_BOSSMODE_PRAC_API UBMAgroCheck : public UBTService
{
	GENERATED_BODY()

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UBehaviorTree* ThisTree;
	ABMAIController* ThisController;
	ABMBossCharacter* ThisAicCharacter;
};
