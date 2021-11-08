// Fill out your copyright notice in the Description page of Project Settings.


#include "Popcorn.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "PopcornGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PoppingPopcorn/PoppingPopcorn.h"

// Sets default values
APopcorn::APopcorn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetSimulatePhysics(true);
	Sprite->SetEnableGravity(true);
	//Sprite->SetConstraintMode(EDOFMode::XZPlane);
	Sprite->SetCollisionProfileName(TEXT("Popcorn"));
	SetRootComponent(Sprite);

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComponent"));
	RadialForceComponent->SetupAttachment(RootComponent);
	RadialForceComponent->ImpulseStrength = PopVelocity;
	RadialForceComponent->Falloff = RIF_Linear;
	RadialForceComponent->Radius = PopImpulseRadius;
	RadialForceComponent->bImpulseVelChange = true;
	RadialForceComponent->bAutoActivate = false;
	RadialForceComponent->bIgnoreOwningActor = false;
	RadialForceComponent->AddCollisionChannelToAffect(ECC_Popcorn);
}

// Called when the game starts or when spawned
void APopcorn::BeginPlay()
{
	Super::BeginPlay();
	
	const int8 RandomRotation = FMath::RandRange(-500, 500);
	const FRotator NewRotation = FRotator(RandomRotation, 0, 0);
	Sprite->AddWorldRotation(NewRotation);

	if(KernelSprites.Num() <= 0)
	{
		return;
	}
	
	const int8 RandomInt = FMath::RandRange(0, KernelSprites.Num() -1);
	Sprite->SetSprite(KernelSprites[RandomInt]);

	float SpawnVelocityMultiplier = FMath::FRandRange(MinSpawnVelocityPercent, MaxSpawnVelocityPercent);
	int8 Direction = FMath::RandBool();
	if(!Direction)
	{
		Direction = -1;
	}
	SpawnVelocityMultiplier = SpawnVelocity * SpawnVelocityMultiplier * Direction;
	Sprite->AddImpulse(GetActorForwardVector() * SpawnVelocityMultiplier);
}

void APopcorn::ExplodePopcorn()
{
	if(IsPendingKill())
	{
		return;
	}
	
	SetLifeSpan(LifeSpanAfterTouched);
	
	if(PopcornSprites.Num() <= 0)
	{
		return;
	}
	
	const int8 RandomInt = FMath::RandRange(0, PopcornSprites.Num() -1);
	Sprite->SetSprite(PopcornSprites[RandomInt]);
	RadialForceComponent->FireImpulse();

    UPopcornGameInstance* GameInstance = Cast<UPopcornGameInstance>(GetGameInstance());
	if(!GameInstance->IsGameSoundMuted())
	{
		UGameplayStatics::PlaySound2D(GetWorld(), PopcornPopSound);
	}
}

