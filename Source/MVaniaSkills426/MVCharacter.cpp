// Fill out your copyright notice in the Description page of Project Settings.


#include "MVCharacter.h"

// Sets default values
AMVCharacter::AMVCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DoubleJumpData.Title = FText::FromString(TEXT("Learned Double Jump!"));
	DoubleJumpData.InputButton.SetResourceObject(LoadObject<UTexture2D>(this, 
		TEXT("Texture2D'/Game/Textures/T_Button_A.T_Button_A'")));
	DoubleJumpData.SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_DoubleJump.T_Icon_DoubleJump'")));
	DoubleJumpData.SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_DoubleJump.T_Image_DoubleJump'")));

	BackDashData.Title = FText::FromString(TEXT("Learned Back Dash!"));
	BackDashData.InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Button_Y.T_Button_Y'")));
	BackDashData.SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_BackDash.T_Icon_BackDash'")));
	BackDashData.SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_BackDash.T_Image_BackDash'")));

	BMagicFireballData.Title = FText::FromString(TEXT("Learned Fireball!"));
	BMagicFireballData.InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_RTrigger_01.T_RTrigger_01'")));
	BMagicFireballData.SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Fireball.T_Fireball'")));
		BMagicFireballData.SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	BMagicFireballData.SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_Fireball.T_Image_Fireball'")));
		BMagicFireballData.SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	BMagicFireballData.SkillBorderColor.TintColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	BMagicFireballData.SkillFontColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	BMagicFireballData.bMagicSkill = true;

	FireballAttributes.Name = FText::FromString(TEXT("Fireball"));
	FireballAttributes.ManaCost = 5;
	FireballAttributes.Damage = 50;
	FireballAttributes.DamageType = UDamage_Fire::StaticClass();
	FireballAttributes.IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Fireball.T_Fireball'")));

	BMagicElectroSparkData.Title = FText::FromString(TEXT("Learned ElectroSpark!"));
	BMagicElectroSparkData.InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_RTrigger_01.T_RTrigger_01'")));
	BMagicElectroSparkData.SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ElectroSpark.T_ElectroSpark'")));
		BMagicElectroSparkData.SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	BMagicElectroSparkData.SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_ElectroSpark.T_Image_ElectroSpark'")));
		BMagicElectroSparkData.SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	BMagicElectroSparkData.SkillBorderColor.TintColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	BMagicElectroSparkData.SkillFontColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	BMagicElectroSparkData.bMagicSkill = true;

	ElectroSparkAttributes.Name = FText::FromString(TEXT("ElectroSpark"));
	ElectroSparkAttributes.ManaCost = 25;
	ElectroSparkAttributes.Damage = 100;
	ElectroSparkAttributes.DamageType = UDamage_Lightning::StaticClass();
	ElectroSparkAttributes.IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ElectroSpark.T_ElectroSpark'")));

	BloodlustAttributes.Name = FText::FromString(TEXT("Bloodlust"));
	BloodlustAttributes.ManaCost = 50;
	BloodlustAttributes.Damage = 200;
	BloodlustAttributes.DamageType = UDamage_Blood::StaticClass();
	BloodlustAttributes.IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Bloodlust.T_Bloodlust'")));

	ArcticBlastAttributes.Name = FText::FromString(TEXT("ArcticBlast"));
	ArcticBlastAttributes.ManaCost = 25;
	ArcticBlastAttributes.Damage = 10;
	ArcticBlastAttributes.DamageType = UDamage_Ice::StaticClass();
	ArcticBlastAttributes.IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ArcticBlast.T_ArcticBlast'")));

	WMagicLensOfTruthData.Title = FText::FromString(TEXT("Learned LensOfTruth!"));
	WMagicLensOfTruthData.InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LTrigger_01.T_LTrigger_01'")));
	WMagicLensOfTruthData.SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LensOfTruth.T_LensOfTruth'")));
	WMagicLensOfTruthData.SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	WMagicLensOfTruthData.SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_LensOfTruth.T_Image_LensOfTruth'")));
	WMagicLensOfTruthData.SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	WMagicLensOfTruthData.SkillBorderColor.TintColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	WMagicLensOfTruthData.SkillFontColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	WMagicLensOfTruthData.bMagicSkill = true;

	WMagicMap[E_WMagic::LensOfTruth].Name = FText::FromString(TEXT("LensOfTruth"));
	WMagicMap[E_WMagic::LensOfTruth].ManaCost = 10;
	WMagicMap[E_WMagic::LensOfTruth].Damage = 0;
	WMagicMap[E_WMagic::LensOfTruth].DamageType = UDamage_White::StaticClass();
	WMagicMap[E_WMagic::LensOfTruth].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LensOfTruth.T_LensOfTruth'")));
	WMagicMap[E_WMagic::LensOfTruth].IconSlate.SetImageSize(FVector2D(150.f, 150.f));

	WMagicMistData.Title = FText::FromString(TEXT("Learned Mist!"));
	WMagicMistData.InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LTrigger_01.T_LTrigger_01'")));
	WMagicMistData.SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Mist.T_Mist'")));
	WMagicMistData.SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	WMagicMistData.SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_Mist.T_Image_Mist'")));
	WMagicMistData.SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	WMagicMistData.SkillBorderColor.TintColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	WMagicMistData.SkillFontColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	WMagicMistData.bMagicSkill = true;

	WMagicMap[E_WMagic::Mist].Name = FText::FromString(TEXT("Mist"));
	WMagicMap[E_WMagic::Mist].ManaCost = 10;
	WMagicMap[E_WMagic::Mist].Damage = 0;
	WMagicMap[E_WMagic::Mist].DamageType = UDamage_White::StaticClass();
	WMagicMap[E_WMagic::Mist].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Mist.T_Mist'")));
	WMagicMap[E_WMagic::Mist].IconSlate.SetImageSize(FVector2D(150.f, 150.f));

	WMagicMap[E_WMagic::Shield].Name = FText::FromString(TEXT("Shield"));
	WMagicMap[E_WMagic::Shield].ManaCost = 10;
	WMagicMap[E_WMagic::Shield].Damage = 0;
	WMagicMap[E_WMagic::Shield].DamageType = UDamage_White::StaticClass();
	WMagicMap[E_WMagic::Shield].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Shield.T_Shield'")));
	WMagicMap[E_WMagic::Shield].IconSlate.SetImageSize(FVector2D(150.f, 150.f));

	WMagicMap[E_WMagic::TimeSlow].Name = FText::FromString(TEXT("TimeSlow"));
	WMagicMap[E_WMagic::TimeSlow].ManaCost = 20;
	WMagicMap[E_WMagic::TimeSlow].Damage = 0;
	WMagicMap[E_WMagic::TimeSlow].DamageType = UDamage_White::StaticClass();
	WMagicMap[E_WMagic::TimeSlow].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_TimeSlow.T_TimeSlow'")));
	WMagicMap[E_WMagic::TimeSlow].IconSlate.SetImageSize(FVector2D(150.f, 150.f));
}

// Called when the game starts or when spawned
void AMVCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMVCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMVCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

