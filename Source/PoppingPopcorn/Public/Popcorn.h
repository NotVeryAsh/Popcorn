// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Popcorn.generated.h"

class USphereComponent;
class UPaperSpriteComponent;
class UPaperSprite;

UCLASS()
class POPPINGPOPCORN_API APopcorn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APopcorn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	USoundBase* PopcornPopSound;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Sprites")
	UPaperSpriteComponent* Sprite;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sprites")
	TArray<UPaperSprite*> KernelSprites;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sprites")
	TArray<UPaperSprite*> PopcornSprites;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Movement")
	URadialForceComponent* RadialForceComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
	int32 SpawnVelocity = 5000;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
	int32 SpawnImpulseRadius = 1000;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
	int32 PopVelocity = 7000;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
	int32 PopImpulseRadius = 1000;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
	float MinSpawnVelocityPercent = 70.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement")
	float MaxSpawnVelocityPercent = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="")
	float LifeSpanAfterTouched = 0.5f;
	
public:	 

	UFUNCTION(BlueprintCallable, Category="State")
	void ExplodePopcorn();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Score")
	int32 Score = 1;
};
