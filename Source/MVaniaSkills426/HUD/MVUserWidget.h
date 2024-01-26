// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"
#include "Internationalization/Text.h"
#include "MVUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API UMVUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    UMVUserWidget(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Category = "UI - WM")
	FSlateBrush GetWhiteMagicImage() const;

    UFUNCTION(BlueprintCallable, Category = "UI - WM")
	float GetWhiteMagicPercent() const;

    UFUNCTION(BlueprintCallable, Category = "UI - WM")
	float GetWhiteMagicManacost() const;

    UFUNCTION(BlueprintCallable, Category = "UI - WM")
	FText GetWhiteMagicManacostFText() const;
	
    UFUNCTION(BlueprintCallable, Category = "UI - BM")
	FSlateBrush GetBlackMagicImage() const;

    UFUNCTION(BlueprintCallable, Category = "UI - BM")
	float GetBlackMagicManacost() const;

    UFUNCTION(BlueprintCallable, Category = "UI - BM")
	FText GetBlackMagicManacostFText() const;

protected:
	virtual void NativeOnInitialized() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush MagicEmpty;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Empty = 0.0f;
};
