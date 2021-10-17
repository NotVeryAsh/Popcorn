// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PopcornGameMode.generated.h"

/**
 * 
 */
UCLASS()
class POPPINGPOPCORN_API APopcornGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Game Properties")
	float GameTime = 60.f;
};
