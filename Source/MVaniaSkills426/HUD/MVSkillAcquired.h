// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "Blueprint/UserWidget.h"
#include "Components/BackgroundBlur.h"
#include "Components/Overlay.h"
#include "Components/Image.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"

#include "MVSkillAcquired.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API UMVSkillAcquired : public UUserWidget
{
	GENERATED_BODY()

protected:
	FText M_SkillAcquired_Title_Path = FText::FromString(TEXT("Material'/Game/Materials/M_SkillAcquired_Title.M_SkillAcquired_Title'"));
	FText SkillAcquired_Path = FText::FromString(TEXT("WidgetBlueprint'/Game/SkillAcquired.SkillAcquired'"));
	FText FT_Gothic_Letters_Font_Path = FText::FromString(TEXT("Font'/Game/Fonts/FT_Gothic_Letters_Font.FT_Gothic_Letters_Font'"));
	FText T_Icon_DoubleJump_Path = FText::FromString(TEXT("Texture2D'/Game/Textures/T_Icon_DoubleJump.T_Icon_DoubleJump'"));

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel")
	UCanvasPanel* CanvasPanel;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|BackgroundBlur")
	UBackgroundBlur* BackgroundBlur;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay")
	UOverlay* Skill_Overlay;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay|Skill_BG_Image")
	UImage* Skill_BG_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay|Skill_FG_Image")
	UImage* Skill_FG_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay|Skill_Learned_Box")
	UHorizontalBox* Skill_Learned_Box;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay|Skill_Learned_Box|Skill_Icon_Left")
	UImage* Skill_Icon_Left;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay|Skill_Learned_Box|Skill_Learned_Text")
	UTextBlock* Skill_Learned_Text;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Skill_Overlay|Skill_Learned_Box|Skill_Icon_Right")
	UImage* Skill_Icon_Right;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|ScreenshotBorder")
	UBorder* ScreenshotBorder;

	virtual void NativeOnInitialized() override;
};
