// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/DamageType.h"

#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "Engine/Texture2D.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "UObject/Object.h"
#include "MVTypes.generated.h"

UENUM(BlueprintType)
enum class E_BMagic : uint8
{
    None,
    Fireball,
    ElectroSpark,
    Bloodlust,
    ArcticBlast
};

UENUM(BlueprintType)
enum class E_WMagic : uint8
{
    None,
    LensOfTruth,
    Mist,
    Shield,
    TimeSlow
};

UENUM(BlueprintType)
enum class E_Skills : uint8
{
    None,
    DoubleJump,
    BackDash,
    Fireball,
    ElectroSpark,
    LensOfTruth,
    Mist
};

UCLASS()
class MVANIASKILLS426_API UDamage_Lightning : public UDamageType
{
    GENERATED_BODY()
};

UCLASS()
class MVANIASKILLS426_API UDamage_Fire : public UDamageType
{
    GENERATED_BODY()
};

UCLASS()
class MVANIASKILLS426_API UDamage_Blood : public UDamageType
{
    GENERATED_BODY()
};

UCLASS()
class MVANIASKILLS426_API UDamage_Ice : public UDamageType
{
    GENERATED_BODY()
};

UCLASS()
class MVANIASKILLS426_API UDamage_White : public UDamageType
{
    GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct MVANIASKILLS426_API FSTR_SkillData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush InputButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush SkillIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush SkillImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush SkillBorderColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateColor SkillFontColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMagicSkill;
};

USTRUCT(BlueprintType)
struct MVANIASKILLS426_API FSTR_MagicAttributes
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSlateBrush IconSlate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ManaCost;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UDamageType> DamageType;
};