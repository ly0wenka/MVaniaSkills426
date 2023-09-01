// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MV_PC_Metroidvania.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API AMV_PC_Metroidvania : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController") UUserWidget* WBP_LearnedSkill;
};
