// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MVSkillAcquired.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API UMVSkillAcquired : public UUserWidget
{
	GENERATED_BODY()

	FText M_SkillAcquired_Title_Path = FText::FromString(TEXT("Material'/Game/Materials/M_SkillAcquired_Title.M_SkillAcquired_Title'"));
	FText SkillAcquired_Path = FText::FromString(TEXT("WidgetBlueprint'/Game/SkillAcquired.SkillAcquired'"));
};
