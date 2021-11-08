// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "Sound/AmbientSound.h"
#include "PopcornGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class POPPINGPOPCORN_API UPopcornGameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category="Sound")
	void ToggleMuteGameSounds();

	UFUNCTION(BlueprintCallable, Category="Sound")
	bool IsGameSoundMuted();

	UFUNCTION(BlueprintCallable, Category="Music")
	void ToggleMuteGameMusic();

	UFUNCTION(BlueprintCallable, Category="Music")
	bool IsGameMusicMuted();

	UFUNCTION(BlueprintCallable, Category="Music")
	void LoadBackgroundMusicActor();
	
protected:

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Music")
	AActor* BackgroundMusicActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	bool bIsGameSoundMuted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	bool bIsGameMusicMuted;
};