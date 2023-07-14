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
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "../MVTypes.h"
#include "../MVCharacter.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "MVSkillAcquired.generated.h"

DECLARE_DYNAMIC_DELEGATE_RetVal(FText, FOnSkill_Learned_Text_ChangedSignature);

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
	UCanvasPanel* Canvas_Panel;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|BackgroundBlur")
	UBackgroundBlur* Background_Blur;

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

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|ScreenshotBorder|Screenshot_Image")
	UImage* Screenshot_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Input_Overlay")
	UOverlay* Input_Overlay;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Input_Overlay|Input_Image")
	UImage* Input_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Input_Overlay|Input_Button_Image")
	UImage* Input_Button_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay")
	UOverlay* Description_Overlay;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Description_Image")
	UImage* Description_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Description_Text")
	UTextBlock* Description_Text;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Attributes_Overlay")
	UOverlay* Attributes_Overlay;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Image")
	UImage* Attributes_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box")
	UVerticalBox* Attributes_Box;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box|ManaCost")
	UTextBlock* ManaCost;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box|Mana_Value")
	UTextBlock* Mana_Value;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box|Back_Overlay")
	UOverlay* Back_Overlay;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box|Back_Overlay|Back_Image")
	UImage* Back_Image;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box|Back_Overlay|BackButton")
	UButton* BackButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "CanvasPanel|Description_Overlay|Attributes_Box|Back_Overlay|BackButton|Back_Text")
	UTextBlock* Back_Text;

	virtual void NativeOnInitialized() override;

	FOnSkill_Learned_Text_ChangedSignature OnSkill_Learned_Text_ChangedDelegate;

	UFUNCTION(BlueprintCallable)
	FSTR_SkillData FindSTR_SkillData();

	UFUNCTION(BlueprintCallable)
	FText GetTitle() { return FindSTR_SkillData().Title; }

	UFUNCTION(BlueprintCallable)
    FSlateBrush GetInputButton() { return FindSTR_SkillData().InputButton; }

    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSkillIcon() { return FindSTR_SkillData().SkillIcon; }

    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSkillImage() { return FindSTR_SkillData().SkillImage; }

    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSkillBorderColor() { return FindSTR_SkillData().SkillBorderColor; }

    UFUNCTION(BlueprintCallable)
    FSlateColor GetSkillFontColor() { return FindSTR_SkillData().SkillFontColor; }
};
