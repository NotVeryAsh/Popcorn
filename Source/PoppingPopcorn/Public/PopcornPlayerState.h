// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PopcornPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class POPPINGPOPCORN_API APopcornPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Score")
	void IncrementScore(int32 ScoreValue);

	UFUNCTION(BlueprintCallable, Category="Score")
	void ResetScore();
};
