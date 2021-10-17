// Fill out your copyright notice in the Description page of Project Settings.


#include "PopcornPlayerState.h"

void APopcornPlayerState::IncrementScore(int32 ScoreValue)
{
	SetScore(GetScore() + ScoreValue);
}

void APopcornPlayerState::ResetScore()
{
	SetScore(0);
}
