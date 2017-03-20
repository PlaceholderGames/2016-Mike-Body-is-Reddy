// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleServerBrowser.h"
#include "MyGameMode.h"
#include "MyPlayerState.h"
#include "MyPlayerStart.h"

AMyGameMode::AMyGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonBP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerStateClass = AMyPlayerState::StaticClass();

}

void AMyGameMode::PostLogic(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (NewPlayer)
	{
		AMyPlayerState * PS = Cast<AMyPlayerState>(NewPlayer->PlayerState);
		if (PS && GameState)
		{
			uint8 NumTeamA = 0;
			uint8 NumTeamB = 0;
			for (APlayerState * It : GameState->PlayerArray)
			{
				AMyPlayerState * OtherPS = Cast<AMyPlayerState>(It);
				if (OtherPS)
				{
					if (OtherPS->teamB)
					{
						NumTeamB++;
					}
					else
					{
						NumTeamA++;
					}
				}
			}

			if (NumTeamA > NumTeamB)
			{
				PS->teamB = true;
			}
		}
	}
}

AActor * AMyGameMode::ChoosePlayerStart(AController * Player)
{
	if (Player)
	{
		AMyPlayerState * PS = Cast<AMyPlayerState>(Player->PlayerState);
			if (PS)
			{
				TArray<AMyPlayerStart *> Starts;
				for (TActorIterator<AMyPlayerStart> StartItr(GetWorld()); StartItr; ++StartItr)
				{
					if (StartItr->teamB == PS->teamB)
					{
						Starts.Add(*StartItr);
					}
				}
				return Starts[FMath::RandRange(0, Starts.Num() - 1)];
		}
	}
	return NULL;
}
