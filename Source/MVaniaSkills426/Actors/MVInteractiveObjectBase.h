// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../MVTypes.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "../HUD/MVNotify.h"
#include "Sound/SoundWave.h"
#include "Blueprint/UserWidget.h"
#include "../MVCharacter.h"
#include "MVInteractiveObjectBase.generated.h"

UCLASS()
class MVANIASKILLS426_API AMVInteractiveObjectBase : public AActor, public IInteract
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

	UPROPERTY(EditAnywhere, Category = "InteractiveObjectBase") USceneComponent* DefaultSceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") UBoxComponent* InteractColliderBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") UMVNotify* Notify;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") FText InteractMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") USoundBase* SFXCanInteract;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") AMVCharacter* AsMVCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") TSubclassOf<AMVCharacter> BP_As_Side_Scroller_Character;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObjectBase") TSubclassOf<UUserWidget> BP_Notify;
};
