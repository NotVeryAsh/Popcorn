// Fill out your copyright notice in the Description page of Project Settings.


#include "PopcornGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UPopcornGameInstance::Init()
{
	Super::Init();
	
	UGameplayStatics::PlaySound2D(GetWorld(), BackgroundMusic);
}

void UPopcornGameInstance::MuteSound(bool bMuteSound)
{
	bIsSoundMuted = bMuteSound;
}

void UPopcornGameInstance::MuteMusic(bool bMuteMusic)
{
	bIsMusicMuted = bMuteMusic;
	
	// Find a way to mute sound that is already playing
}
