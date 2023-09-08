// Fill out your copyright notice in the Description page of Project Settings.


#include "MVSkillDoubleJump.h"
#include "UMG/Public/Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h" // Include the StaticMeshComponent header
#include "Components/ParticleSystemComponent.h" // Include the ParticleSystemComponent header
#include "Components/PointLightComponent.h" // Include the PointLightComponent header
#include "Components/BoxComponent.h" // Include the BoxComponent header

AMVSkillDoubleJump::AMVSkillDoubleJump()
{
	Decal_Skill->SetDecalMaterial(LoadObject<UMaterialInterface>(this, TEXT(
		"Material'/Game/Materials/Decal_DoubleJump_Mat.Decal_DoubleJump_Mat'"
	)));

	SM_Candle_Stands[2]->SetVisibility(true);
	SM_Candle_Stands[3]->SetVisibility(true);

	PS_Candle_VFXs[2]->SetAutoActivate(true);
	PS_Candle_VFXs[3]->SetAutoActivate(true);	

	InteractMessage = FText::FromString(TEXT("Learn Skill"));

	InteractColliderBox->OnComponentBeginOverlap.AddDynamic(this, &AMVSkillDoubleJump::OnBeginOverlap);
	//InteractColliderBox->OnComponentEndOverlap.AddDynamic(this, &AMVSkillDoubleJump::OnEndOverlap);
}

void AMVSkillDoubleJump::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AMVSkillDoubleJump::PlayerAcquiredSkillFX_Implementation()
{
	check(Notify);
	if (Notify && Notify->GetParent())
	{
		if (UWidgetTree* WidgetTree = Notify->WidgetTree)
		{
			// Remove the widget from its parent
			WidgetTree->RemoveWidget(Notify);
		}
	}

	//const FText P_OrePile_Explosion_Success_Path = FText::FromString(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Treasure/Resources/P_OrePile_Explosion_Success.P_OrePile_Explosion_Success'"));
	ParticleSystemTemplate = LoadObject<UParticleSystem>(nullptr, TEXT("/Game/InfinityBladeEffects/Effects/FX_Treasure/Resources/P_OrePile_Explosion_Success.P_OrePile_Explosion_Success"));
	check(ParticleSystemTemplate);
	if (ParticleSystemTemplate)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ParticleSystemTemplate, Skill_Mesh->GetComponentLocation(), FRotator::ZeroRotator);
	}

	check(SFX_SkillAcquire);
	if (SFX_SkillAcquire)
	{
		UGameplayStatics::PlaySound2D(this, SFX_SkillAcquire, 3.0f);
	}
	TArray<USceneComponent*> SCs = { InteractColliderBox, Skill_Mesh, Skill_VFX, Skill_Light };
	for (USceneComponent* SC : SCs)
	{
		if (SC)
		{
			SC->DestroyComponent();
		}
	}
	


}
//void AMVSkillDoubleJump::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//void AMVSkillDoubleJump::OnEndOverlap(UPrimitiveComponent* OnComponentEndOverlap, UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
//{
//
//}
