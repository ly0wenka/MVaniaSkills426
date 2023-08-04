// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

#include "MVNotify.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API UMVNotify : public UUserWidget
{
	GENERATED_BODY()

protected:
	FText Image_BGPINK_T_Ink_Pink_Path = FText::FromString(TEXT("Texture2D'/Game/Textures/T_Ink_Pink.T_Ink_Pink'"));
	FText Image_BGBLACK_T_Ink_Black_Path = FText::FromString(TEXT("Texture2D'/Game/Textures/T_Ink_Black.T_Ink_Black'"));
	FText Image_Button_Iteract_T_Button_B_Path = FText::FromString(TEXT("Texture2D'/Game/Textures/T_Button_B.T_Button_B'"));

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel") UCanvasPanel* Canvas_Panel;
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel") UImage* Image_BGPINK;
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel") UImage* Image_BGBLACK;
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel") UImage* Image_BGBLACK_180;
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel") UTextBlock* TextBlock_MESSAGE;
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category="CanvasPanel") UImage* Image_Button_Iteract;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText ReceivedMessage = FText::FromString(TEXT("ReceivedMessage"));
	UFUNCTION(BlueprintCallable) FText Get_MESSAGE_Text() { return ReceivedMessage; }
};
