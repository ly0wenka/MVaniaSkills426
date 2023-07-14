// Fill out your copyright notice in the Description page of Project Settings.


#include "MVCharacter.h"

// Sets default values
AMVCharacter::AMVCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkillAcquiredMap[E_Skills::DoubleJump].Title = FText::FromString(TEXT("Learned Double Jump!"));
	SkillAcquiredMap[E_Skills::DoubleJump].InputButton.SetResourceObject(LoadObject<UTexture2D>(this, 
		TEXT("Texture2D'/Game/Textures/T_Button_A.T_Button_A'")));
	SkillAcquiredMap[E_Skills::DoubleJump].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_DoubleJump.T_Icon_DoubleJump'")));
	SkillAcquiredMap[E_Skills::DoubleJump].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_DoubleJump.T_Image_DoubleJump'")));

	SkillAcquiredMap[E_Skills::BackDash].Title = FText::FromString(TEXT("Learned Back Dash!"));
	SkillAcquiredMap[E_Skills::BackDash].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Button_Y.T_Button_Y'")));
	SkillAcquiredMap[E_Skills::BackDash].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_BackDash.T_Icon_BackDash'")));
	SkillAcquiredMap[E_Skills::BackDash].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_BackDash.T_Image_BackDash'")));

	SkillAcquiredMap[E_Skills::Fireball].Title = FText::FromString(TEXT("Learned Fireball!"));
	SkillAcquiredMap[E_Skills::Fireball].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_RTrigger_01.T_RTrigger_01'")));
	SkillAcquiredMap[E_Skills::Fireball].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Fireball.T_Fireball'")));
		SkillAcquiredMap[E_Skills::Fireball].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::Fireball].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_Fireball.T_Image_Fireball'")));
		SkillAcquiredMap[E_Skills::Fireball].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::Fireball].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::Fireball].SkillFontColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::Fireball].bMagicSkill = true;

	BMagicMap[E_BMagic::Fireball].Name = FText::FromString(TEXT("Fireball"));
	BMagicMap[E_BMagic::Fireball].ManaCost = 5;
	BMagicMap[E_BMagic::Fireball].Damage = 50;
	BMagicMap[E_BMagic::Fireball].DamageType = UDamage_Fire::StaticClass();
	BMagicMap[E_BMagic::Fireball].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Fireball.T_Fireball'")));

	SkillAcquiredMap[E_Skills::ElectroSpark].Title = FText::FromString(TEXT("Learned ElectroSpark!"));
	SkillAcquiredMap[E_Skills::ElectroSpark].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_RTrigger_01.T_RTrigger_01'")));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ElectroSpark.T_ElectroSpark'")));
		SkillAcquiredMap[E_Skills::ElectroSpark].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_ElectroSpark.T_Image_ElectroSpark'")));
		SkillAcquiredMap[E_Skills::ElectroSpark].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillFontColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::ElectroSpark].bMagicSkill = true;

	BMagicMap[E_BMagic::ElectroSpark].Name = FText::FromString(TEXT("ElectroSpark"));
	BMagicMap[E_BMagic::ElectroSpark].ManaCost = 25;
	BMagicMap[E_BMagic::ElectroSpark].Damage = 100;
	BMagicMap[E_BMagic::ElectroSpark].DamageType = UDamage_Lightning::StaticClass();
	BMagicMap[E_BMagic::ElectroSpark].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ElectroSpark.T_ElectroSpark'")));

	BMagicMap[E_BMagic::Bloodlust].Name = FText::FromString(TEXT("Bloodlust"));
	BMagicMap[E_BMagic::Bloodlust].ManaCost = 50;
	BMagicMap[E_BMagic::Bloodlust].Damage = 200;
	BMagicMap[E_BMagic::Bloodlust].DamageType = UDamage_Blood::StaticClass();
	BMagicMap[E_BMagic::Bloodlust].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Bloodlust.T_Bloodlust'")));

	BMagicMap[E_BMagic::ArcticBlast].Name = FText::FromString(TEXT("ArcticBlast"));
	BMagicMap[E_BMagic::ArcticBlast].ManaCost = 25;
	BMagicMap[E_BMagic::ArcticBlast].Damage = 10;
	BMagicMap[E_BMagic::ArcticBlast].DamageType = UDamage_Ice::StaticClass();
	BMagicMap[E_BMagic::ArcticBlast].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ArcticBlast.T_ArcticBlast'")));

	SkillAcquiredMap[E_Skills::LensOfTruth].Title = FText::FromString(TEXT("Learned LensOfTruth!"));
	SkillAcquiredMap[E_Skills::LensOfTruth].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LTrigger_01.T_LTrigger_01'")));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LensOfTruth.T_LensOfTruth'")));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_LensOfTruth.T_Image_LensOfTruth'")));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillFontColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::LensOfTruth].bMagicSkill = true;

	WMagicMap[E_WMagic::LensOfTruth].Name = FText::FromString(TEXT("LensOfTruth"));
	WMagicMap[E_WMagic::LensOfTruth].ManaCost = 10;
	WMagicMap[E_WMagic::LensOfTruth].Damage = 0;
	WMagicMap[E_WMagic::LensOfTruth].DamageType = UDamage_White::StaticClass();
	WMagicMap[E_WMagic::LensOfTruth].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LensOfTruth.T_LensOfTruth'")));
	WMagicMap[E_WMagic::LensOfTruth].IconSlate.SetImageSize(FVector2D(150.f, 150.f));

	SkillAcquiredMap[E_Skills::Mist].Title = FText::FromString(TEXT("Learned Mist!"));
	SkillAcquiredMap[E_Skills::Mist].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LTrigger_01.T_LTrigger_01'")));
	SkillAcquiredMap[E_Skills::Mist].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Mist.T_Mist'")));
	SkillAcquiredMap[E_Skills::Mist].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::Mist].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_Mist.T_Image_Mist'")));
	SkillAcquiredMap[E_Skills::Mist].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::Mist].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::Mist].SkillFontColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::Mist].bMagicSkill = true;

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

