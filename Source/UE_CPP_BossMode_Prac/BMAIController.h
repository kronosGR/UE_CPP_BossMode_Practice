// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BMAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_BOSSMODE_PRAC_API ABMAIController : public AAIController
{
	GENERATED_BODY()


public:
	ABMAIController();
	virtual void OnPossess(APawn* InPawn) override;

	UBlackboardComponent* GetBlackboard();

protected:
	UPROPERTY(BlueprintReadWrite, Category=Behavior)
	UBlackboardComponent* BlackboardComponent;

	UPROPERTY(BlueprintReadWrite, Category=Behavior)
	UBehaviorTreeComponent* BehaviorTreeComp;
};
