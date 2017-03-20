// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleServerBrowser.h"
#include "MyPlayerState.h"
#include "UnrealNetwork.h"

void AMyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyPlayerState, teamB);
}