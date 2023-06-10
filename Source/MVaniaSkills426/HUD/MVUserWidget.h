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
    UFUNCTION(BlueprintCallable, Category = "UI")
	FSlateBrush GetWhiteMagicImage() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
	float GetWhiteMagicPercent() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
	float GetWhiteMagicManacost() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
	FText GetWhiteMagicManacostFText() const;

protected:
	virtual void NativeOnInitialized() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush MagicEmpty;
};
