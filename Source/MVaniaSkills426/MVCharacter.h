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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Double Jump")
	bool bHasDoubleJump;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill - Double Jump")
	FSTR_SkillData DoubleJumpData;

};
