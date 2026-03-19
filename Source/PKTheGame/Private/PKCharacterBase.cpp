// Fill out your copyright notice in the Description page of Project Settings.


#include "PKCharacterBase.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APKCharacterBase::APKCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 800.f;
	SpringArm->bUsePawnControlRotation = true;
	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	PlayerCamera->SetupAttachment(SpringArm);
	
	GetMesh()->SetRelativeRotation(FRotator{0.f, -90.f, 0.f});
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	WeaponMesh->SetupAttachment(GetMesh());
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

void APKCharacterBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	WeaponMesh->AttachToComponent(
		GetMesh(),
		FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		HandleSocket
		);
}

void APKCharacterBase::PlayerJump()
{
	Jump();
}

void APKCharacterBase::PlayerMove(const FInputActionValue& ActionValue)
{
	FVector2D ActionVector = ActionValue.Get<FVector2D>();
	
	AddMovementInput(GetActorForwardVector(), ActionVector.Y);
	AddMovementInput(GetActorRightVector(), ActionVector.X);
	
	// GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Turquoise, TEXT("MOVING!"));
}

void APKCharacterBase::PlayerShoot()
{
	FVector SocketLocation = WeaponMesh->GetSocketLocation(ProjectileMuzzleSocket);
	FRotator SocketRotation = PlayerCamera->GetComponentRotation();
	
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	
	 GetWorld()->SpawnActor<AActor>(
	 	Projectile,
	 	SocketLocation,
	 	SocketRotation,
	 	SpawnParameters
	 );
}

void APKCharacterBase::PlayerLook(const FInputActionValue& ActionValue)
{
	FVector2D ActionRotation = ActionValue.Get<FVector2D>();
	
	AddControllerYawInput(ActionRotation.X);	
	AddControllerPitchInput(ActionRotation.Y);
}

