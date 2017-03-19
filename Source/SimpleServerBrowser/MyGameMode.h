// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESERVERBROWSER_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AMyGameMode(const FObjectInitializer& ObjectInitializer);

	void PostLogic(APlayerController * NewPlayer);
	AActor * ChoosePlayerStart(AController * Player);
	bool ShouldSpawnAtStartSpot(AController * Player) override { return false; };
};
