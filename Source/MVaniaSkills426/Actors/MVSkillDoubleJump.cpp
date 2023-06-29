// Fill out your copyright notice in the Description page of Project Settings.


#include "MVSkillDoubleJump.h"

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
}