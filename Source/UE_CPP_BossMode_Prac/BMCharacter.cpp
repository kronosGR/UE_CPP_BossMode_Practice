// Fill out your copyright notice in the Description page of Project Settings.


#include "BMCharacter.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ABMCharacter::ABMCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	FPCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPCameraComponent->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	FPCameraComponent->AddRelativeLocation(FVector(0, 0, 64.f));
	FPCameraComponent->bUsePawnControlRotation = true;

	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1O"));
	FPMesh->SetOnlyOwnerSee(true);
	FPMesh->AttachToComponent(FPCameraComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FPMesh->bCastDynamicShadow = false;
	FPMesh->CastShadow = false;

	FPGunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_GUN"));
	FPGunMesh->SetOnlyOwnerSee(true);
	FPGunMesh->bCastDynamicShadow = false;
	FPGunMesh->CastShadow = false;

	FPGunMesh->AttachToComponent(FPMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),
	                             TEXT("GripPoint"));
}

// Called when the game starts or when spawned
void ABMCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABMCharacter::MoveForward(float Val)
{
	if (Val != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Val);
	}
}

void ABMCharacter::MoveRight(float Val)
{
	if (Val != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Val);
	}
}

void ABMCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABMCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Called every frame
void ABMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABMCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABMCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABMCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABMCharacter::LookUpAtRate);
}
