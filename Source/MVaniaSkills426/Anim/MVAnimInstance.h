// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MVAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API UMVAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill - Double Jump") bool bIsDoubleJumping = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill - Double Jump") int32 JumpCount = 0;
};
