// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESERVERBROWSER_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(Replicated)
	bool teamB;
	
	
	
};
