// Fill out your copyright notice in the Description page of Project Settings.


#include "PKInteractableObject.h"


// Sets default values
APKInteractableObject::APKInteractableObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APKInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APKInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APKInteractableObject::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, "INTERACT OBJECT RESPONDS");
	

}

