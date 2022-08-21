// Fill out your copyright notice in the Description page of Project Settings.


#include "BMAgroCheck.h"

void UBMAgroCheck::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (ThisTree == nullptr || ThisController == nullptr || ThisAicCharacter == nullptr)
	{
		ThisTree = OwnerComp.GetCurrentTree();
		ThisController = Cast<ABMAIController>(OwnerComp.GetAIOwner());
		ThisAicCharacter = Cast<ABMBossCharacter>(ThisController->GetPawn());

		if (ThisTree == nullptr || ThisController == nullptr || ThisAicCharacter == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Warning Argo Service performed on invalid AI"));
			return;
		}
	}
}
