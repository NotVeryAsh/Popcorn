// Fill out your copyright notice in the Description page of Project Settings.


#include "PopcornSpawner.h"

#include "Popcorn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APopcornSpawner::APopcornSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APopcornSpawner::BeginPlay()
{
	Super::BeginPlay();

	StartGame();
	
	GameState = Cast<APopcornGameState>(GetWorld()->GetGameState());
}

void APopcornSpawner::StartGame()
{
    AccumulatedSpawnTime = 0.f;
	CurrentSpawnTime = SpawnTime;
}

// Called every frame
void APopcornSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!GameState)
	{
		return;
	}
	
	if(!GameState->IsGameRunning)
	{
		return;
	}
	
	if(AccumulatedSpawnTime >= CurrentSpawnTime)
	{
		SpawnPopcorn();

		AccumulatedSpawnTime = 0;
		
		CurrentSpawnTime -= CurrentSpawnTime*SpawnTimeDecrement;
	}
	
	AccumulatedSpawnTime += DeltaTime;
}

void APopcornSpawner::SpawnPopcorn()
{
	if(!IsValid(PopcornClass))
	{
		return;
	}
	
	
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
	const FVector Location = GetActorLocation();
	const FRotator Rotation = GetActorRotation();
	GetWorld()->SpawnActor(PopcornClass, &Location, &Rotation, SpawnParameters);
}