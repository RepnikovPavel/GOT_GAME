// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
// #include "IWebSocket.h"
#include "CppGameInst.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UCppGameInst : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
	virtual void Shutdown() override;
	// TSharedPtr<IWebSocket> WebSocketPtr;
	
};
