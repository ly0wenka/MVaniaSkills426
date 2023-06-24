// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVInteractiveObjectBase.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/DecalComponent.h"
#include "Sound/SoundBase.h"
#include "MVSkillBase.generated.h"

UCLASS()
class USMPSComponent : public UObject
{
	GENERATED_BODY()
	
public:
	USMPSComponent() = default;
	USMPSComponent(UStaticMeshComponent* InSM, UParticleSystemComponent* InPS) :
		SM(InSM), PS(InPS) {}
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SM")
	UStaticMeshComponent* SM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PS")
	UParticleSystemComponent* PS;
};
/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API AMVSkillBase : public AMVInteractiveObjectBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMVSkillBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dias")
	UStaticMeshComponent* Dias;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill_Mesh")
	UStaticMeshComponent* Skill_Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill_Mesh|Skill_VFX")
	UParticleSystemComponent* Skill_VFX;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill_Mesh|Skill_Light")
	UPointLightComponent* Skill_Light;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SM_Candle_Stands")
	TArray<UStaticMeshComponent*> SM_Candle_Stands;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PS_Candle_Stands")
	TArray<UParticleSystemComponent*> PS_Candle_VFXs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SM_Candles_Dias_Range")
	TArray<UStaticMeshComponent*> SM_Candles_Dias_Range;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Decal")
	UDecalComponent* Decal_Skill;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Statue")
	UStaticMeshComponent* Statue;

	UPROPERTY(EditAnywhere, Category="SFX_SkillAcquire")
	USoundBase* SFX_SkillAcquire;
};