// Fill out your copyright notice in the Description page of Project Settings.


#include "MVSkillBase.h"
#include "Engine/StaticMesh.h"
#include "Math/Rotator.h"
#include "Particles/ParticleSystem.h"
#include "Math/Color.h"
#include "Templates/SharedPointer.h"
#include "Templates/SharedPointerInternals.h"

AMVSkillBase::AMVSkillBase()
{
	Dias = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Dias"));
	Dias->SetRelativeScale3D(FVector(.6,.3,.8));
	Dias->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT(
		"StaticMesh'/Game/InfinityBladeFireLands/Environments/Fire/Fire_Fortress/SM/Env_Fire_MelancholicTroll03.Env_Fire_MelancholicTroll03'"
	)));
	Dias->SetupAttachment(RootComponent);

	Skill_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Skill_Mesh"));
	Skill_Mesh->SetRelativeLocation(FVector(0., 0., 160.));
	Skill_Mesh->SetRelativeRotation(FRotator(0., 0., 90.));
	Skill_Mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT(
		"StaticMesh'/Game/MV/StaticMeshes/SM_MoveSkill.SM_MoveSkill'"
	)));
	Skill_Mesh->SetupAttachment(RootComponent);

	Skill_VFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Skill_VFX"));
	Skill_VFX->SetRelativeLocation(FVector(0., 0., 40.));
	Skill_VFX->SetTemplate(LoadObject<UParticleSystem>(this, TEXT(
		"ParticleSystem'/Game/Particles/P_Skill.P_Skill'"
	)));
	Skill_VFX->SetupAttachment(Skill_Mesh);

	Skill_Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Skill_Light"));
	Skill_Light->SetIntensity(25.);
	Skill_Light->SetLightColor(FLinearColor(0.14996, 0.14996, 0.));
	Skill_Light->SetupAttachment(Skill_Mesh);

	const int32 CandleStandsLength = 4;
	for (int32 i = 0; i < CandleStandsLength; ++i)
	{
		auto* Candle_Stand = CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("Candle_Stand_%d"), i+1));
		Candle_Stand->SetRelativeLocation(FVector(195.f, .0f, .0f));
		Candle_Stand->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT(
			"StaticMesh'/Game/InfinityBladeEffects/Effects/FX_Meshes/Mobile/SM_CandleStand_03.SM_CandleStand_03'"
		)));
		Candle_Stand->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT(
			"Material'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_deco/Materials/M_Candle_glowing.M_Candle_glowing'"
		)));
		Candle_Stand->SetVisibility(false);
		Candle_Stand->SetupAttachment(RootComponent);
		SM_Candle_Stands.Add(Candle_Stand);

		auto* Candle_VFX = CreateDefaultSubobject<UParticleSystemComponent>(*FString::Printf(TEXT("Candle_VFX_%d"), i+1));
		Candle_VFX->SetRelativeLocation(FVector(.0f, .0f, 220.f));
		Candle_VFX->SetRelativeScale3D(FVector(1.5f));
		Candle_VFX->SetTemplate(LoadObject<UParticleSystem>(this, TEXT(
			"ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Ambient/Lighting/P_LightCorona.P_LightCorona'"
		)));
		Candle_VFX->SetAutoActivate(false);
		Candle_VFX->SetupAttachment(Candle_Stand);
		PS_Candle_VFXs.Add(Candle_VFX);
	}

	SM_Candle_Stands[1]->SetRelativeLocation(FVector(-195.0f, .0f, .0f));

	SM_Candle_Stands[2]->SetRelativeLocation(FVector(-120.0f, -100.0f, .0f));
	SM_Candle_Stands[2]->SetRelativeRotation(FRotator(.0f, .0f, -110.0f));
	SM_Candle_Stands[2]->SetRelativeScale3D(FVector(1.2f));

	SM_Candle_Stands[3]->SetRelativeLocation(FVector(120.0f, -100.0f, .0f));
	SM_Candle_Stands[3]->SetRelativeRotation(FRotator(.0f, .0f, -160.0f));
	SM_Candle_Stands[3]->SetRelativeScale3D(FVector(1.2f));

	PS_Candle_VFXs[3]->SetRelativeRotation(FRotator(.0f, .0f, 50.0f));
	
	const int32 SM_Candles_Dias_RangeLength = 2;
	for (int32 i = 0; i < SM_Candles_Dias_RangeLength; ++i)
	{
		auto* Candles_Dias_ = CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("Candles_Dias_%d"), i + 1));
		Candles_Dias_->SetRelativeLocation(FVector(-90.f, 24.f, 95.f));
		Candles_Dias_->SetRelativeRotation(FRotator(.0f, .0f, -90.0f));
		Candles_Dias_->SetRelativeScale3D(FVector(3., 3., 3.));
		Candles_Dias_->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT(
			"StaticMesh'/Game/InfinityBladeEffects/Effects/FX_Meshes/Mobile/SM_Candle_Drips_3.SM_Candle_Drips_3'"
		)));
		Candles_Dias_->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT(
			"Material'/Game/InfinityBladeFireLands/Environments/Fire/Env_Fire_deco/Materials/M_Candle_glowing.M_Candle_glowing'"
		)));
		Candles_Dias_->SetVisibility(false);
		SM_Candles_Dias_Range.Add(Candles_Dias_);
	}

	SM_Candles_Dias_Range[1]->SetRelativeLocation(FVector(90, 20, 100));
	SM_Candles_Dias_Range[1]->SetRelativeRotation(FRotator(.0f, .0f, -40.0f));

	Decal_Skill = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal_Skill"));
	Decal_Skill->SetRelativeLocation(FVector(.0f, .0f, 120.f));
	Decal_Skill->SetRelativeRotation(FRotator(.0f, -90.0f, .0f));
	Decal_Skill->SetRelativeScale3D(FVector(0.1f));
	Decal_Skill->DecalSize = FVector(256.0f, 300.0f, 400.f);
	Decal_Skill->SetupAttachment(RootComponent);

	Statue = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Statue"));
	Statue->SetRelativeLocation(FVector(.0f, -120.0f, -10.f));
	Statue->SetRelativeScale3D(FVector(1.2f, 1.f, 0.9f));
	Statue->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT(
		"StaticMesh'/Game/InfinityBladeIceLands/Environments/Ice/EXO_RockyRuins/StaticMesh/SM_Statue01.SM_Statue01'"
	)));
	Statue->SetVisibility(false);
	Statue->SetupAttachment(RootComponent);


	SFX_SkillAcquire = LoadObject<USoundBase>(this, TEXT(
		"SoundWave'/Game/Audio/SFX_SkillAcquired.SFX_SkillAcquired'"
	));
}
