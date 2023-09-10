// Fill out your copyright notice in the Description page of Project Settings.


#include "MV_PC_Metroidvania.h"
#include "Kismet/GameplayStatics.h"

void AMV_PC_Metroidvania::ShowAcquiredSkill_Implementation()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	WBP_LearnedSkill->AddToViewport(0);
}
