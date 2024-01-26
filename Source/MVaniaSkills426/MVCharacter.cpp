// Fill out your copyright notice in the Description page of Project Settings.


#include "MVCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMVCharacter::AMVCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkillAcquiredMap[E_Skills::None].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Magic_Empty.T_Magic_Empty'")));

	SkillAcquiredMap[E_Skills::DoubleJump].Title = FText::FromString(TEXT("Learned Double Jump!"));
	SkillAcquiredMap[E_Skills::DoubleJump].Description = FText::FromString(TEXT("Allows player to jump again in mid-air."));
	SkillAcquiredMap[E_Skills::DoubleJump].InputButton.SetResourceObject(LoadObject<UTexture2D>(this, 
		TEXT("Texture2D'/Game/Textures/T_Button_A.T_Button_A'")));
	SkillAcquiredMap[E_Skills::DoubleJump].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_DoubleJump.T_Icon_DoubleJump'")));
	SkillAcquiredMap[E_Skills::DoubleJump].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_DoubleJump.T_Image_DoubleJump'")));

	SkillAcquiredMap[E_Skills::BackDash].Title = FText::FromString(TEXT("Learned Back Dash!"));
	SkillAcquiredMap[E_Skills::BackDash].Description = FText::FromString(TEXT("Back Dash!"));
	SkillAcquiredMap[E_Skills::BackDash].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Button_Y.T_Button_Y'")));
	SkillAcquiredMap[E_Skills::BackDash].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_BackDash.T_Icon_BackDash'")));
	SkillAcquiredMap[E_Skills::BackDash].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_BackDash.T_Image_BackDash'")));

	SkillAcquiredMap[E_Skills::Fireball].Title = FText::FromString(TEXT("Learned Fireball!"));
	SkillAcquiredMap[E_Skills::Fireball].Description = FText::FromString(TEXT("Unleash the power of the elements with Cast Out Ranged Fireball!"));
	SkillAcquiredMap[E_Skills::Fireball].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_RTrigger_01.T_RTrigger_01'")));
	SkillAcquiredMap[E_Skills::Fireball].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_Fireball.T_Icon_Fireball'")));
		SkillAcquiredMap[E_Skills::Fireball].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::Fireball].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_Fireball.T_Image_Fireball'")));
		SkillAcquiredMap[E_Skills::Fireball].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::Fireball].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::Fireball].SkillFontColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::Fireball].bMagicSkill = true;

	MagicMap[E_Skills::None].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Magic_Empty.T_Magic_Empty'")));

	MagicMap[E_Skills::Fireball].Name = FText::FromString(TEXT("Fireball"));
	MagicMap[E_Skills::Fireball].ManaCost = 5;
	MagicMap[E_Skills::Fireball].Damage = 50;
	MagicMap[E_Skills::Fireball].DamageType = UDamage_Fire::StaticClass();
	MagicMap[E_Skills::Fireball].MagicType = E_Magic_Type::BMagic;
	MagicMap[E_Skills::Fireball].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Fireball.T_Fireball'")));

	SkillAcquiredMap[E_Skills::ElectroSpark].Title = FText::FromString(TEXT("Learned ElectroSpark!"));
	SkillAcquiredMap[E_Skills::ElectroSpark].Description = FText::FromString(TEXT("This ElectroSpark spell allows you to conjure a fiery projectile and hurl it at your enemies from a distance. Harnessing the forces of fire, you can rain down destruction upon your foes with precision and intensity."));
	SkillAcquiredMap[E_Skills::ElectroSpark].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_RTrigger_01.T_RTrigger_01'")));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_ElectroSpark.T_Icon_ElectroSpark'")));
		SkillAcquiredMap[E_Skills::ElectroSpark].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_ElectroSpark.T_Image_ElectroSpark'")));
		SkillAcquiredMap[E_Skills::ElectroSpark].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::ElectroSpark].SkillFontColor = FSlateColor(FLinearColor(.08f, .005f, .035f));
	SkillAcquiredMap[E_Skills::ElectroSpark].bMagicSkill = true;

	MagicMap[E_Skills::ElectroSpark].Name = FText::FromString(TEXT("ElectroSpark"));
	MagicMap[E_Skills::ElectroSpark].ManaCost = 25;
	MagicMap[E_Skills::ElectroSpark].Damage = 100;
	MagicMap[E_Skills::ElectroSpark].DamageType = UDamage_Lightning::StaticClass();
	MagicMap[E_Skills::ElectroSpark].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ElectroSpark.T_ElectroSpark'")));
	MagicMap[E_Skills::ElectroSpark].MagicType = E_Magic_Type::BMagic;

	MagicMap[E_Skills::Bloodlust].Name = FText::FromString(TEXT("Bloodlust"));
	MagicMap[E_Skills::Bloodlust].ManaCost = 50;
	MagicMap[E_Skills::Bloodlust].Damage = 200;
	MagicMap[E_Skills::Bloodlust].DamageType = UDamage_Blood::StaticClass();
	MagicMap[E_Skills::Bloodlust].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Bloodlust.T_Bloodlust'")));
	MagicMap[E_Skills::Bloodlust].MagicType = E_Magic_Type::BMagic;

	MagicMap[E_Skills::ArcticBlast].Name = FText::FromString(TEXT("ArcticBlast"));
	MagicMap[E_Skills::ArcticBlast].ManaCost = 25;
	MagicMap[E_Skills::ArcticBlast].Damage = 10;
	MagicMap[E_Skills::ArcticBlast].DamageType = UDamage_Ice::StaticClass();
	MagicMap[E_Skills::ArcticBlast].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_ArcticBlast.T_ArcticBlast'")));
	MagicMap[E_Skills::ArcticBlast].MagicType = E_Magic_Type::BMagic;

	SkillAcquiredMap[E_Skills::LensOfTruth].Title = FText::FromString(TEXT("Learned LensOfTruth!"));
	SkillAcquiredMap[E_Skills::LensOfTruth].Description = FText::FromString(TEXT("LensOfTruth!"));
	SkillAcquiredMap[E_Skills::LensOfTruth].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LTrigger_01.T_LTrigger_01'")));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_LensOfTruth.T_Icon_LensOfTruth'")));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_LensOfTruth.T_Image_LensOfTruth'")));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::LensOfTruth].SkillFontColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::LensOfTruth].bMagicSkill = true;

	MagicMap[E_Skills::LensOfTruth].Name = FText::FromString(TEXT("LensOfTruth"));
	MagicMap[E_Skills::LensOfTruth].ManaCost = 10;
	MagicMap[E_Skills::LensOfTruth].Damage = 0;
	MagicMap[E_Skills::LensOfTruth].DamageType = UDamage_White::StaticClass();
	MagicMap[E_Skills::LensOfTruth].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LensOfTruth.T_LensOfTruth'")));
	MagicMap[E_Skills::LensOfTruth].IconSlate.SetImageSize(FVector2D(150.f, 150.f));
	MagicMap[E_Skills::LensOfTruth].MagicType = E_Magic_Type::WMagic;

	SkillAcquiredMap[E_Skills::Mist].Title = FText::FromString(TEXT("Learned Mist!"));
	SkillAcquiredMap[E_Skills::Mist].Description = FText::FromString(TEXT("Mist!"));
	SkillAcquiredMap[E_Skills::Mist].InputButton.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_LTrigger_01.T_LTrigger_01'")));
	SkillAcquiredMap[E_Skills::Mist].SkillIcon.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Icon_Mist.T_Icon_Mist'")));
	SkillAcquiredMap[E_Skills::Mist].SkillIcon.SetImageSize(FVector2D(200.f, 200.f));
	SkillAcquiredMap[E_Skills::Mist].SkillImage.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Image_Mist.T_Image_Mist'")));
	SkillAcquiredMap[E_Skills::Mist].SkillImage.SetImageSize(FVector2D(64.f, 64.f));
	SkillAcquiredMap[E_Skills::Mist].SkillBorderColor.TintColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::Mist].SkillFontColor = FSlateColor(FLinearColor(.7f, .7f, 1.0f));
	SkillAcquiredMap[E_Skills::Mist].bMagicSkill = true;

	MagicMap[E_Skills::Mist].Name = FText::FromString(TEXT("Mist"));
	MagicMap[E_Skills::Mist].ManaCost = 10;
	MagicMap[E_Skills::Mist].Damage = 0;
	MagicMap[E_Skills::Mist].DamageType = UDamage_White::StaticClass();
	MagicMap[E_Skills::Mist].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Mist.T_Mist'")));
	MagicMap[E_Skills::Mist].IconSlate.SetImageSize(FVector2D(150.f, 150.f));
	MagicMap[E_Skills::Mist].MagicType = E_Magic_Type::WMagic;

	MagicMap[E_Skills::Shield].Name = FText::FromString(TEXT("Shield"));
	MagicMap[E_Skills::Shield].ManaCost = 10;
	MagicMap[E_Skills::Shield].Damage = 0;
	MagicMap[E_Skills::Shield].DamageType = UDamage_White::StaticClass();
	MagicMap[E_Skills::Shield].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_Shield.T_Shield'")));
	MagicMap[E_Skills::Shield].IconSlate.SetImageSize(FVector2D(150.f, 150.f));
	MagicMap[E_Skills::Shield].MagicType = E_Magic_Type::WMagic;

	MagicMap[E_Skills::TimeSlow].Name = FText::FromString(TEXT("TimeSlow"));
	MagicMap[E_Skills::TimeSlow].ManaCost = 20;
	MagicMap[E_Skills::TimeSlow].Damage = 0;
	MagicMap[E_Skills::TimeSlow].DamageType = UDamage_White::StaticClass();
	MagicMap[E_Skills::TimeSlow].IconSlate.SetResourceObject(LoadObject<UTexture2D>(this,
		TEXT("Texture2D'/Game/Textures/T_TimeSlow.T_TimeSlow'")));
	MagicMap[E_Skills::TimeSlow].IconSlate.SetImageSize(FVector2D(150.f, 150.f));
	MagicMap[E_Skills::TimeSlow].MagicType = E_Magic_Type::WMagic;
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

void AMVCharacter::PressedInputActionBackDash(bool& IsFacingRight)
{
	if (bIsBackDashing && bBackDashReady && !GetCharacterMovement()->IsFlying())
	{
		bBackDashReady = true;
		FTimerHandle TimerHandle;
		FTimerDelegate Delegate;
		Delegate.BindLambda([&](){});
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, Delegate, BackDashCooldown, false);
		bBackDashReady = false;

		bIsBackDashing = true;
		IsFacingRight = false;
		if (GetCapsuleComponent()->GetComponentRotation().Yaw >= 0)
		{
			IsFacingRight = true;
		}
	}
}

