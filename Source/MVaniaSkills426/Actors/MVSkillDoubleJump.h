// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVSkillBase.h"
#include "MVSkillDoubleJump.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FComponentBeginOverlapSignature, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp);

/**
 * 
 */
UCLASS()
class MVANIASKILLS426_API AMVSkillDoubleJump : public AMVSkillBase
{
	GENERATED_BODY()

public:
	AMVSkillDoubleJump();

	UFUNCTION() void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION() void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);
};
