// Fill out your copyright notice in the Description page of Project Settings.


#include "BMAgroCheck.h"

#include "BehaviorTree/BlackboardComponent.h"

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

	FCollisionQueryParams SphereSweepParams(FName(TEXT("AgroCheckSweep")), true, ThisAicCharacter);
	FCollisionObjectQueryParams ObjectQuery(ECC_GameTraceChannel1);

	FHitResult HitOut(ForceInit);

	DrawDebugSphere(ThisAicCharacter->GetWorld(), ThisAicCharacter->GetActorLocation(), 1500, 12, FColor::Red, false,
	                4.f);

	bool bResult = ThisAicCharacter->GetWorld()->SweepSingleByObjectType(HitOut, ThisAicCharacter->GetActorLocation(),
	                                                                     ThisAicCharacter->GetActorLocation() + FVector(
		                                                                     0.f, 0.f, 10.f), FQuat(), ObjectQuery,
	                                                                     FCollisionShape::MakeSphere(1500),
	                                                                     SphereSweepParams);
	if (bResult)
	{
		ThisController->GetBlackboard()->SetValueAsObject(TEXT("TargetToFollow"), HitOut.GetActor());
		ThisController->GetBlackboard()->SetValueAsVector(TEXT("HomeLocation"), ThisAicCharacter->GetActorLocation());
		ThisController->GetBlackboard()->SetValueAsVector(TEXT("TargetLocation"), HitOut.GetActor()->GetActorLocation());
	} else
	{
		ThisController->GetBlackboard()->SetValueAsObject(TEXT("TargetToFollow"),nullptr);
	}
}
