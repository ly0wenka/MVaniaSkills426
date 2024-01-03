// Fill out your copyright notice in the Description page of Project Settings.


#include "MV_Character_Enemy_Base.h"

// Sets default values
AMV_Character_Enemy_Base::AMV_Character_Enemy_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMV_Character_Enemy_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMV_Character_Enemy_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMV_Character_Enemy_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

