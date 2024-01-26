// Fill out your copyright notice in the Description page of Project Settings.


#include "MVUserWidget.h"
#include "../MVCharacter.h"
#include "../MVTypes.h"

UMVUserWidget::UMVUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MagicEmpty.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Magic_Empty.T_Magic_Empty'")));
}

void UMVUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

FSlateBrush UMVUserWidget::GetWhiteMagicImage() const
{
	const auto lC = Cast<AMVCharacter>(GetOwningPlayerPawn());
	if (!lC) return MagicEmpty;
	const auto slot = lC->WMagicSlotted;
	return slot == E_WMagic::None ? MagicEmpty : lC->MagicMap[static_cast<E_Skills>(slot)].IconSlate;
}

float UMVUserWidget::GetWhiteMagicPercent() const
{
	const auto lC = Cast<AMVCharacter>(GetOwningPlayerPawn());
	if (!lC) return Empty;
	const auto slot = lC->WMagicSlotted;
	switch (slot)
	{
	case E_WMagic::None:
		return Empty;
		break;
	case E_WMagic::LensOfTruth:
		return lC->LensOfTruthCooldownTimePercent;
		break;
	case E_WMagic::Mist:
		return lC->MistCooldownTimePercent;
		break;
	case E_WMagic::Shield:
		return lC->ShieldCooldownTimePercent;
		break;
	case E_WMagic::TimeSlow:
		return lC->TimeSlowCooldownTimePercent;
		break;
	default:
		break;
	}

	return Empty;
}

float UMVUserWidget::GetWhiteMagicManacost() const
{
	const auto lC = Cast<AMVCharacter>(GetOwningPlayerPawn());
	if (!lC) return Empty;
	const auto slot = lC->WMagicSlotted;
	return slot == E_WMagic::None ? Empty : lC->MagicMap[static_cast<E_Skills>(slot)].ManaCost;
}

FText UMVUserWidget::GetWhiteMagicManacostFText() const
{
	return FText::FromString(FString::FromInt(FMath::RoundToInt(GetWhiteMagicManacost())));
}

FSlateBrush UMVUserWidget::GetBlackMagicImage() const
{
	const auto lC = Cast<AMVCharacter>(GetOwningPlayerPawn());
	if (!lC) return MagicEmpty;
	const auto slot = lC->BMagicSlotted;
	return slot == E_BMagic::None ? MagicEmpty : lC->MagicMap[static_cast<E_Skills>(slot)].IconSlate;
}

float UMVUserWidget::GetBlackMagicManacost() const
{
	const auto lC = Cast<AMVCharacter>(GetOwningPlayerPawn());
	if (!lC) return Empty;
	const auto slot = lC->BMagicSlotted;
	return slot == E_BMagic::None ? Empty : lC->MagicMap[static_cast<E_Skills>(slot)].ManaCost;
}

FText UMVUserWidget::GetBlackMagicManacostFText() const
{
	return FText::FromString(FString::FromInt(FMath::RoundToInt(GetBlackMagicManacost())));
}
