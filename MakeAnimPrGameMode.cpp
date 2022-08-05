// Copyright Epic Games, Inc. All Rights Reserved.

#include "MakeAnimPrGameMode.h"
#include "MakeAnimPrCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMakeAnimPrGameMode::AMakeAnimPrGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
