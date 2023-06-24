// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MVInteractiveObjectBase.generated.h"

UCLASS()
class MVANIASKILLS426_API AMVInteractiveObjectBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMVInteractiveObjectBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "InteractiveObjectBase")
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(VisibleAnywhere, Category = "InteractiveObjectBase")
	UBoxComponent* InteractColliderBox;
};
