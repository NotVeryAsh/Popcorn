// Fill out your copyright notice in the Description page of Project Settings.

#include "PopcornGameState.h"

#include "Popcorn.h"
#include "PopcornGameMode.h"
#include "PopcornSpawner.h"
#include "Kismet/GameplayStatics.h"

void APopcornGameState::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APopcornPlayerController>(GetWorld()->GetFirstPlayerController());
	if(!IsValid(PlayerController))
	{
		return;
	}

	const APopcornGameMode* GameMode = Cast<APopcornGameMode>(GetWorld()->GetAuthGameMode());
	
	if(IsValid(GameMode))
	{
		TimeLeft = GameMode->GameTime;
	}
}

void APopcornGameState::StartGame()
{
	const APopcornGameMode* GameMode = Cast<APopcornGameMode>(GetWorld()->GetAuthGameMode());
	
	if(IsValid(GameMode))
	{
		TimeLeft = GameMode->GameTime;
	}

	TArray<AActor*> Spawners;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APopcornSpawner::StaticClass(), Spawners);

	APopcornSpawner* Spawner = Cast<APopcornSpawner>(Spawners[0]);
	
	if(IsValid(Spawner))
	{
		Spawner->StartGame();
	}
	
	IsGameRunning = true;
	GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &APopcornGameState::DecreaseGameTimer, 1.0f, true);
	PlayerController->StartGame();
}

void APopcornGameState::EndGame()
{
	IsGameRunning = false;
	GetWorld()->GetTimerManager().ClearTimer(GameTimer);
	PlayerController->EndGame();
	
	TArray<AActor*> Popcorns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PopcornClass, Popcorns);

	for (AActor* Popcorn : Popcorns)
	{
		Popcorn->Destroy();
	}
}

void APopcornGameState::DecreaseGameTimer()
{
	if(TimeLeft <= 0.0f)
	{
		EndGame();	
	}

	TimeLeft--;
}