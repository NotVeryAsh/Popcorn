// Fill out your copyright notice in the Description page of Project Settings.


#include "PopcornGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UPopcornGameInstance::Init()
{
	Super::Init();
}

void UPopcornGameInstance::LoadBackgroundMusicActor()
{
	TArray<AActor*> AmbientSounds;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAmbientSound::StaticClass(), AmbientSounds);

	BackgroundMusicActor = AmbientSounds[0];
}

bool UPopcornGameInstance::IsGameMusicMuted()
{
	return bIsGameMusicMuted;
}

void UPopcornGameInstance::ToggleMuteGameMusic()
{
	bIsGameMusicMuted = !bIsGameMusicMuted;

	AAmbientSound* BackgroundMusic = Cast<AAmbientSound>(BackgroundMusicActor);

	if(!bIsGameMusicMuted)
	{
		BackgroundMusic->Play();
	} else
	{
		BackgroundMusic->Stop();
	}
}

void UPopcornGameInstance::ToggleMuteGameSounds()
{
	bIsGameSoundMuted = !bIsGameSoundMuted;
}

bool UPopcornGameInstance::IsGameSoundMuted()
{
	return bIsGameSoundMuted;
}