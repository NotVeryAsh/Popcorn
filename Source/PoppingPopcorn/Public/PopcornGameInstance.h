// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
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
	void MuteSound(bool bMuteSound);

	UFUNCTION(BlueprintCallable, Category="Sound")
	void MuteMusic(bool bMuteMusic);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Sound")
	bool bIsMusicMuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Sound")
	bool bIsSoundMuted;
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound")
	USoundBase* BackgroundMusic;	
};