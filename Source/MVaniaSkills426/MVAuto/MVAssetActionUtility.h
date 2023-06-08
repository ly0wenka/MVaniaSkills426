// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "EditorAssetLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleEmitter.h"
#include "Particles/ParticleLODLevel.h"
#include "Particles/Color/ParticleModuleColorOverLife.h"
#include "EditorUtilityLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "MaterialEditingLibrary.h"
#include "NiagaraStackGraphUtilitiesAdapterLibrary.h"
#include "Distributions/DistributionVector.h"
#include "Distributions/DistributionVectorConstantCurve.h"
#include "MVAssetActionUtility.generated.h"

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API UMVAssetActionUtility : public UAssetActionUtility
{
	GENERATED_BODY()
private:
	void P(FString Message)
	{
		if (ensure(GEngine))
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Cyan, Message);
		}
	}
	TArray<UObject*> GetSelectedAssets()
	{
		UObject* WorldContextObject = nullptr; // Provide a valid World Context object
		TArray<UObject*> SelectedAssets = UEditorUtilityLibrary::GetSelectedAssets();

		int32 NumAssets = SelectedAssets.Num();

		UE_LOG(LogTemp, Warning, TEXT("Selected %d asset/s"), NumAssets);
		return SelectedAssets;
	}
public:
	UFUNCTION(CallInEditor)
	void SetTextureGroup()
	{
		TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
		if (SelectedObjects.Num() <= 0)
		{
			return;
		}
		UObject* SelectedObject = SelectedObjects[0];
		P("Hello");
	}

	UFUNCTION(CallInEditor)
	void SetColorOverLife()
	{
		UObject* WorldContextObject = nullptr; // Provide a valid World Context object
		TArray<UObject*> SelectedAssets;
		SelectedAssets = UEditorUtilityLibrary::GetSelectedAssets(); //WorldContextObject

		int32 SetAssets = 0;

		for (UObject* Asset : SelectedAssets)
		{
			if (Asset->GetClass() != UParticleSystem::StaticClass())
				continue;

			UParticleSystem* ParticleSystem = Cast<UParticleSystem>(Asset);
			TArray<UParticleEmitter*>& Emitters = ParticleSystem->Emitters;
			const TMap<int32, int32> EmitModuleMap = { {1, 3}, {2, 3}, { 5, 1} };
			const TMap<int32, int32> EmitMinEnabledMap = { {1, 1}, {2, 1}, { 5, 0} };
			const TMap<FString, TArray<float>> FNameColorMap = {
				{"P_WMagic", {0.7, 0.7, 1}},
				{"P_BMagic", {0.08, 0.005, 0.035}},
				{"P_Skill", {1, 1, 0}}};
			// emitters indexes = 1, 2, 5
			// modules indexes = 3, 3, 1
			// max min update? (1, 1), (1, 1), (1, 0)
			// FVector(0.7,0.7,0.1) P_WMagic
			// FVector(0.08, 0.005, 0.035) P_BMagic
			// FVector(1, 1, 0) P_Particle

			TArray<float> SetVec = FNameColorMap[Asset->GetName()];
			for (int32 i = 0; i < Emitters.Num(); ++i)
			{
				UParticleEmitter* Emitter = Emitters[i];
				FString EmitterName = Emitter->GetEmitterName().ToString();
				UE_LOG(LogTemp, Warning, TEXT("Emitter Name: %s"), *EmitterName);
				if (EmitModuleMap.Find(i) == nullptr)
				{

					continue;
				}

				UParticleLODLevel* LODLevel = Emitter->GetLODLevel(0);
				TArray<UParticleModule*>& Modules = LODLevel->Modules;
				/*if (!Modules.Contains(EmitModuleMap[i]))
				{
					continue;
				}*/
				UParticleModuleColorOverLife* LifetimeEmitter = Cast<UParticleModuleColorOverLife>(Modules[EmitModuleMap[i]]);

				for (int32 irgb = 0; irgb < SetVec.Num(); ++irgb) 
				{
					LifetimeEmitter->ColorOverLife.Distribution->SetKeyOut(irgb, 0, SetVec[irgb]); //maxRGB
				}
				if (!EmitMinEnabledMap[i])
				{
					continue;					
				}
				for (int32 irgb = 0; irgb < SetVec.Num(); ++irgb)
				{
					LifetimeEmitter->ColorOverLife.Distribution->SetKeyOut(irgb, 1, SetVec[irgb]); //minRGB
				}
			}

			UE_LOG(LogTemp, Warning, TEXT("Setting for asset %s"), *Asset->GetName());
			SetAssets++;
		}

		UE_LOG(LogTemp, Warning, TEXT("Setting set for %d assets"), SetAssets);
	}
};
