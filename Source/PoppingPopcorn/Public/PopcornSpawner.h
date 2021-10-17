// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PopcornGameState.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "PopcornSpawner.generated.h"

UCLASS()
class POPPINGPOPCORN_API APopcornSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	APopcornSpawner();
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawning")
	float SpawnTimeDecrement = 0.003f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawning")
	float SpawnTime = 0.3f;

	UFUNCTION(BlueprintCallable, Category="Game State")
	void StartGame();	
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Spawning")
	float CurrentSpawnTime;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Spawning")
	float AccumulatedSpawnTime;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Game State")
	APopcornGameState* GameState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawning")
	UClass* PopcornClass;
	
	UFUNCTION(BlueprintCallable, Category="Spawning")
	void SpawnPopcorn();
};
