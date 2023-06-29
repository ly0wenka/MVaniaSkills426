// Fill out your copyright notice in the Description page of Project Settings.


#include "MVInteractiveObjectBase.h"
#include "NavAreas/NavArea_Obstacle.h"
#include "Blueprint/UserWidget.h"
#include "Sound/SoundWave.h"
#include "../HUD/MVNotify.h"
#include "WidgetBlueprint.h"
#include "Components/Widget.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AMVInteractiveObjectBase::AMVInteractiveObjectBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;
	
	InteractColliderBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractColliderBox"));
	InteractColliderBox->AreaClass = UNavArea_Obstacle::StaticClass();
	InteractColliderBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	InteractColliderBox->SetupAttachment(RootComponent);

	SFXCanInteract = LoadObject<USoundWave>(this, TEXT(
		"SoundWave'/Engine/VREditor/Sounds/UI/Floating_UI_Close.Floating_UI_Close'"
	));
}

// Called when the game starts or when spawned
void AMVInteractiveObjectBase::BeginPlay()
{
	Super::BeginPlay();

	const UWidgetBlueprint* WidgetBlueprint = LoadObject<UWidgetBlueprint>(nullptr, TEXT("WidgetBlueprint'/Game/Notify.Notify'"));
	if (WidgetBlueprint)
	{
		UUserWidget* UserWidget = WidgetBlueprint->GeneratedClass->GetDefaultObject<UUserWidget>();
		if (UserWidget)
		{
			UserWidget->AddToViewport();
		}
	}
	
	/*UMVNotify* NotifyWidget = CreateWidget<UMVNotify>(GetWorld(), UMVNotify::StaticClass());
	if (NotifyWidget)
	{
		NotifyWidget->AddToViewport();
	}*/
}

// Called every frame
void AMVInteractiveObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

