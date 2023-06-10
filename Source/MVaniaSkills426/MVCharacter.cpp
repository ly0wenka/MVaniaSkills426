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

	ElectroSparkAttributes.Name = FText::FromString(TEXT("ElectroSpark"));
	ElectroSparkAttributes.ManaCost = 25;
	ElectroSparkAttributes.Damage = 100;
	ElectroSparkAttributes.DamageType = UDamage_Lightning::StaticClass();
	ElectroSparkAttributes.IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ElectroSpark.T_ElectroSpark'")));

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

