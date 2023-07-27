// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVTypes.h"
#include "GameFramework/Character.h"
#include "MVCharacter.generated.h"

UCLASS()
class MVANIASKILLS426_API AMVCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMVCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
    E_BMagic BMagicSlotted;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
	E_WMagic WMagicSlotted;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
	E_Skills SkillAcquired;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
	bool bWMagicReady { true };
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Double Jump")
	bool bHasDoubleJump;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Back Dash")
	bool bHasBackDash;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	bool bHasBMagicFireball;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	bool bHasBMagicElectroSpark;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Bloodlust")
	bool bHasBMagicBloodlust;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ArcticBlast")
	bool bHasBMagicArcticBlast;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	bool bHasWMagicLensOfTruth;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	bool bIsUsingLensOfTruth;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	float LensOfTruthActiveTimePercent = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	float LensOfTruthCooldownTimePercent = 0.0f;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	bool bHasWMagicMist;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	bool bIsUsingMist;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	float MistActiveTimePercent = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	float MistCooldownTimePercent = 0.0f;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Shield")
	bool bHasWMagicShield = true;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Shield")
	float ShieldCooldownTimePercent = 0.0f;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - TimeSlow")
	bool bHasWMagicTimeSlow = true;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - TimeSlow")
	float TimeSlowCooldownTimePercent = 0.0f;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic")
	TMap<E_Skills, FSTR_MagicAttributes> MagicMap = {
		{E_Skills::None, FSTR_MagicAttributes()},
		{E_Skills::Fireball, FSTR_MagicAttributes()},
		{E_Skills::ElectroSpark, FSTR_MagicAttributes()},
		{E_Skills::Bloodlust, FSTR_MagicAttributes()},
		{E_Skills::ArcticBlast, FSTR_MagicAttributes()},
		{E_Skills::LensOfTruth, FSTR_MagicAttributes()},
		{E_Skills::Mist, FSTR_MagicAttributes()},
		{E_Skills::Shield, FSTR_MagicAttributes()},
		{E_Skills::TimeSlow, FSTR_MagicAttributes()}
	};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - SkillAcquiredMap")
	TMap<E_Skills, FSTR_SkillData> SkillAcquiredMap = {
		{E_Skills::None, FSTR_SkillData()},
		{E_Skills::DoubleJump, FSTR_SkillData()},
		{E_Skills::BackDash, FSTR_SkillData()},
		{E_Skills::Fireball, FSTR_SkillData()},
		{E_Skills::ElectroSpark, FSTR_SkillData()},
		{E_Skills::LensOfTruth, FSTR_SkillData()},
		{E_Skills::Mist, FSTR_SkillData()}
	};
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interact")
	bool bCanInteract;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interact")
	int32 InteractTraceLength = 100;
};
