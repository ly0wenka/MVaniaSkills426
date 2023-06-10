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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Double Jump")
	FSTR_SkillData DoubleJumpData;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Back Dash")
	bool bHasBackDash;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Back Dash")
	FSTR_SkillData BackDashData;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	bool bHasBMagicFireball;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	FSTR_SkillData BMagicFireballData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	FSTR_MagicAttributes FireballAttributes;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	bool bHasBMagicElectroSpark;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	FSTR_SkillData BMagicElectroSparkData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	FSTR_MagicAttributes ElectroSparkAttributes;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Bloodlust")
	bool bHasBMagicBloodlust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Bloodlust")
	FSTR_MagicAttributes BloodlustAttributes;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ArcticBlast")
	bool bHasBMagicArcticBlast;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ArcticBlast")
	FSTR_MagicAttributes ArcticBlastAttributes;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	bool bHasWMagicLensOfTruth;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	bool bIsUsingLensOfTruth;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	float LensOfTruthActiveTimePercent = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	float LensOfTruthCooldownTimePercent = 0.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - LensOfTruth")
	FSTR_SkillData WMagicLensOfTruthData;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	bool bHasWMagicMist;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	bool bIsUsingMist;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	float MistActiveTimePercent = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	float MistCooldownTimePercent = 0.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White - Mist")
	FSTR_SkillData WMagicMistData;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic White")
	TMap<E_WMagic, FSTR_MagicAttributes> WMagicMap = {
		{E_WMagic::None, FSTR_MagicAttributes()},
		{E_WMagic::LensOfTruth, FSTR_MagicAttributes()},
		{E_WMagic::Mist, FSTR_MagicAttributes()},
		{E_WMagic::Shield, FSTR_MagicAttributes()},
		{E_WMagic::TimeSlow, FSTR_MagicAttributes()}
	};
};
