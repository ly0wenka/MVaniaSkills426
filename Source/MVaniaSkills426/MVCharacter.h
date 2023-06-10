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

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
    E_BMagic BMagicSlotted;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
	E_WMagic WMagicSlotted;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
	E_Skills SkillAcquired;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Info")
	bool bWMagicReady { true };
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Double Jump")
	bool bHasDoubleJump;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Double Jump")
	FSTR_SkillData DoubleJumpData;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Back Dash")
	bool bHasBackDash;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Back Dash")
	FSTR_SkillData BackDashData;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	bool bHasBMagicFireball;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	FSTR_SkillData BMagicFireballData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Fireball")
	FSTR_MagicAttributes FireballAttributes;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	bool bHasBMagicElectroSpark;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	FSTR_SkillData BMagicElectroSparkData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ElectroSpark")
	FSTR_MagicAttributes ElectroSparkAttributes;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Bloodlust")
	bool bHasBMagicBloodlust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - Bloodlust")
	FSTR_MagicAttributes BloodlustAttributes;
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ArcticBlast")
	bool bHasBMagicArcticBlast;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Magic Black - ArcticBlast")
	FSTR_MagicAttributes ArcticBlastAttributes;
};
