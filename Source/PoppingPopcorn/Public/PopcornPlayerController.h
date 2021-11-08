// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PopcornPlayerController.generated.h"

class UUserWidget;
/**
 * 
 */
UCLASS()
class POPPINGPOPCORN_API APopcornPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	APopcornPlayerController();
	
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void TouchPopcorn(ETouchIndex::Type Index, FVector Location);

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Widgets")
	TSubclassOf<UUserWidget> MenuWidgetClass;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Widgets")
	UUserWidget* MenuWidget;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Widgets")
	UUserWidget* MenuButtonsWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Widgets")
	TSubclassOf<UUserWidget> MenuButtonsWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Widgets")
	TSubclassOf<UUserWidget> GameTimerWidgetClass;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Widgets")
	UUserWidget* GameTimerWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Widgets")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Widgets")
	UUserWidget* GameOverWidget;
	
public:

	UFUNCTION(Category="Game State")
	void EndGame() const;

	UFUNCTION(Category="Game State")
	void StartGame() const;

	UFUNCTION(BlueprintCallable, Category="Game State")
	void ShowMenu();
};
