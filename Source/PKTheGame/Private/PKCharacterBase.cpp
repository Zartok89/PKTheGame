// Fill out your copyright notice in the Description page of Project Settings.


#include "PKCharacterBase.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
APKCharacterBase::APKCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APKCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
			{
				Subsystem->AddMappingContext(MappingContext, 0);
			}
		}
	}
	
}

// Called every frame
void APKCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APKCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APKCharacterBase::PlayerJump);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APKCharacterBase::PlayerMove);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &APKCharacterBase::PlayerShoot);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APKCharacterBase::PlayerLook);
	}
}

void APKCharacterBase::PlayerJump()
{
	Jump();
}

void APKCharacterBase::PlayerMove()
{
	
}

void APKCharacterBase::PlayerShoot()
{
}

void APKCharacterBase::PlayerLook()
{
}

