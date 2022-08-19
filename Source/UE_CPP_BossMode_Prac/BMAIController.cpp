// Fill out your copyright notice in the Description page of Project Settings.


#include "BMAIController.h"

#include "BMBossCharacter.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ABMAIController::ABMAIController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	check(BlackboardComponent);

	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	check(BehaviorTreeComp);
}

void ABMAIController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);

	ABMBossCharacter* possesedPawn = Cast<ABMBossCharacter>(InPawn);
	if (InPawn != nullptr)
	{
		BlackboardComponent->InitializeBlackboard(*(possesedPawn->BehaviorTree->BlackboardAsset));
		BehaviorTreeComp->StartTree(*(possesedPawn->BehaviorTree));
	}
}

UBlackboardComponent* ABMAIController::GetBlackboard()
{
	return BlackboardComponent;
}
