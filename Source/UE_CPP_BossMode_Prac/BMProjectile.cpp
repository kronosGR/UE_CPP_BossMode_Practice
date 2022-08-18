// Fill out your copyright notice in the Description page of Project Settings.


#include "BMProjectile.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABMProjectile::ABMProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	ProjCollision->InitSphereRadius(10.f);
	ProjCollision->SetCollisionProfileName("BlockAll");
	ProjCollision->OnComponentHit.AddDynamic(this, &ABMProjectile::OnHit);
	ProjCollision->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	ProjCollision->CanCharacterStepUpOn = ECB_No;
	RootComponent = ProjCollision;

	OnDestroyed.AddDynamic(this, &ABMProjectile::OnDestroyedProjectile);

	ProjMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ProjMesh->AttachToComponent(ProjCollision, FAttachmentTransformRules::KeepRelativeTransform);
	ProjMesh->SetCollisionProfileName(TEXT("NoCollision"));

	ProjParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	ProjParticle->bAutoActivate = false;
	ProjParticle->AttachToComponent(ProjCollision, FAttachmentTransformRules::KeepRelativeTransform);

	ProjMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Comp"));
	ProjMovement->UpdatedComponent = ProjCollision;
	ProjMovement->InitialSpeed = 3000.f;
	ProjMovement->MaxSpeed = 3000.f;
	ProjMovement->bRotationFollowsVelocity = true;

	InitialLifeSpan = 3.f;
}

void ABMProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                          FVector NormalImpulse,
                          const FHitResult& Hit)
{
	if(!OtherActor->GetClass()->IsChildOf(this->StaticClass()))
	{
		ProjCollision->SetCollisionProfileName(TEXT("NoCollision"));
		ProjCollision->SetGenerateOverlapEvents(false);
		ProjMesh->SetVisibility(false);

		ProjParticle->Activate();
		ProjParticle->DetachFromParent(true);
	}
}

void ABMProjectile::OnDestroyedProjectile(AActor* Actor)
{
}

// Called when the game starts or when spawned
void ABMProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABMProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
