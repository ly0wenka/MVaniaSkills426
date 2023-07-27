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
#include "UObject/Interface.h"
#include "MVTypes.generated.h"

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class E_BMagic : uint8
{
    None = 0,
    Fireball = 1 << 3,
    ElectroSpark = 1 << 4,
    Bloodlust = 1 << 5,
    ArcticBlast = 1 << 6,
};
ENUM_CLASS_FLAGS(E_BMagic);

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class E_WMagic : uint8
{
    None = 0,
    LensOfTruth = 1 << 7,
    Mist = 2 << 0,
    Shield = 2 << 1,
    TimeSlow = 2 << 2
};
ENUM_CLASS_FLAGS(E_WMagic);

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class E_Magic_Type : uint8
{
    WMagic = 0,
    BMagic = 1 << 0,
};
ENUM_CLASS_FLAGS(E_Magic_Type);

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class E_Skills : uint8
{
    None = 0,
    DoubleJump = 1 << 1,
    BackDash = 1 << 2,
    Fireball = E_BMagic::Fireball,
    ElectroSpark = 1 << 4,
    Bloodlust = 1 << 5,
    ArcticBlast = 1 << 6,
    LensOfTruth = E_WMagic::LensOfTruth,
    Mist = 2 << 0,
    Shield = 2 << 1,
    TimeSlow = 2 << 2,
    WMagic = LensOfTruth | Mist | Shield | TimeSlow,
    BMagic = Fireball | ElectroSpark | Bloodlust | ArcticBlast,
};
ENUM_CLASS_FLAGS(E_Skills);

UINTERFACE(BlueprintType)
class MVANIASKILLS426_API UInteract : public UInterface {
    GENERATED_BODY()
};

class MVANIASKILLS426_API IInteract {
    GENERATED_BODY()
public:

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
    void ObjectInteractedWith();
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    E_Magic_Type MagicType;
};