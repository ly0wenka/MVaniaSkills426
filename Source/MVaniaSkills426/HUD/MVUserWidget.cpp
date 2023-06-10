// Fill out your copyright notice in the Description page of Project Settings.


#include "MVUserWidget.h"
#include "../MVCharacter.h"
#include "../MVTypes.h"

void UMVUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	MagicEmpty.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Magic_Empty.T_Magic_Empty'")));
}

FSlateBrush UMVUserWidget::GetWhiteMagicImage() const
{
	const auto lPlayerPawn = GetOwningPlayerPawn();
	const auto lC = Cast<AMVCharacter>(lPlayerPawn);

	if (!lPlayerPawn && !lC)
	{
		return MagicEmpty;
	}
	E_WMagic slot = lC->WMagicSlotted;

	return slot == E_WMagic::None ? MagicEmpty : lC->WMagicMap[slot].IconSlate;
}

float UMVUserWidget::GetWhiteMagicPercent() const
{
	const auto empty = 0.0f;
	const auto lPlayerPawn = GetOwningPlayerPawn();
	const auto lC = Cast<AMVCharacter>(lPlayerPawn);

	if (!lPlayerPawn && !lC)
	{
		return empty;
	}
	E_WMagic slot = lC->WMagicSlotted;
	switch (slot)
	{
	case E_WMagic::None:
		return empty;
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

	return empty;
}

float UMVUserWidget::GetWhiteMagicManacost() const
{
	const auto empty = 0.0f;

	const auto lPlayerPawn = GetOwningPlayerPawn();
	const auto lC = Cast<AMVCharacter>(lPlayerPawn);

	if (!lPlayerPawn && !lC)
	{
		return empty;
	}
	E_WMagic slot = lC->WMagicSlotted;
	
	return slot == E_WMagic::None ? empty : lC->WMagicMap[slot].ManaCost;
}

FText UMVUserWidget::GetWhiteMagicManacostFText() const
{
	return FText::FromString(FString::FromInt(FMath::RoundToInt(GetWhiteMagicManacost())));
}
