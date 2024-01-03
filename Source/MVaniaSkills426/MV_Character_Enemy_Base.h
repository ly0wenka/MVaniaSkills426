// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MVTypes.h"
#include "MV_Character_Enemy_Base.generated.h"

UCLASS()
class MVANIASKILLS426_API AMV_Character_Enemy_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMV_Character_Enemy_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MV_Character_Enemy_Base") TSubclassOf<UDamageType> DamageVulnerableClass = UDamage_Fire::StaticClass();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MV_Character_Enemy_Base") TSubclassOf<UDamageType> DamageResistanceClass = UDamage_Lightning::StaticClass();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MV_Character_Enemy_Base") float VulnerableMultiplier = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MV_Character_Enemy_Base") float ResistantMultiplier = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MV_Character_Enemy_Base") float HP = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MV_Character_Enemy_Base") float IncomingBaseDamage = 0.0f;
};
