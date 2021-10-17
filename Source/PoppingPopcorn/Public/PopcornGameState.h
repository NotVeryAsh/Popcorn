// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PopcornPlayerController.h"
#include "GameFramework/GameStateBase.h"
#include "PopcornGameState.generated.h"

/**
 * 
 */
UCLASS()
class POPPINGPOPCORN_API APopcornGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Game State")
	float TimeLeft;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Game State")
	bool IsGameRunning = false;

	UFUNCTION(BlueprintCallable, Category="Game State")
	void StartGame();	

	UFUNCTION(BlueprintCallable, Category="Game State")
	void EndGame();
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Popcorn")
	UClass* PopcornClass;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Game Timer")
	FTimerHandle GameTimer;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Player")
	APopcornPlayerController* PlayerController;
	
	UFUNCTION(Category="Game Timer")
	void DecreaseGameTimer();

	virtual void BeginPlay() override;
};
