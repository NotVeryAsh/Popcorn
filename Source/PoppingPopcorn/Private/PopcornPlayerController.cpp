// Fill out your copyright notice in the Description page of Project Settings.


#include "PopcornPlayerController.h"
#include "Popcorn.h"
#include "PopcornPlayerState.h"
#include "Camera/CameraActor.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

APopcornPlayerController::APopcornPlayerController()
{
}

void APopcornPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

	MenuWidget = CreateWidget(this, MenuWidgetClass);
	GameTimerWidget = CreateWidget(this, GameTimerWidgetClass);
	GameOverWidget = CreateWidget(this, GameOverWidgetClass);
	
	if (!MenuWidget)
	{
		return;
	}

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	SetViewTarget(CameraActors[0]);
	
	ShowMenu();
}

void APopcornPlayerController::ShowMenu()
{
	GameOverWidget->RemoveFromViewport();
	GameTimerWidget->RemoveFromViewport();
	MenuWidget->AddToViewport();
}

void APopcornPlayerController::StartGame() const
{
	GameOverWidget->RemoveFromViewport();
	MenuWidget->RemoveFromViewport();
	GameTimerWidget->AddToViewport();
	APopcornPlayerState* PopcornPlayerState = Cast<APopcornPlayerState>(PlayerState);
	PopcornPlayerState->ResetScore();
}

void APopcornPlayerController::EndGame() const
{
	GameTimerWidget->RemoveFromParent();
	GameOverWidget->AddToViewport();
}

void APopcornPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindTouch(IE_Pressed, this, &APopcornPlayerController::TouchPopcorn);
}

void APopcornPlayerController::TouchPopcorn(ETouchIndex::Type Index, FVector Location)
{
	FHitResult HitResult;
	GetHitResultUnderFinger(Index, ECollisionChannel::ECC_Visibility, true, HitResult);

	APopcornPlayerState* GamePlayerState = Cast<APopcornPlayerState>(PlayerState);
	APopcorn* HitPopcorn = Cast<APopcorn>(HitResult.GetActor());
	if(HitPopcorn && GamePlayerState)
	{
		HitPopcorn->ExplodePopcorn();
		GamePlayerState->IncrementScore(HitPopcorn->Score);
	}
}
