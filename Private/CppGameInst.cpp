// Fill out your copyright notice in the Description page of Project Settings.


#include "CppGameInst.h"
// #include "WebSocketsModule.h"

void UCppGameInst::Init()
{
	Super::Init();
	// if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	// {
	// 	FModuleManager::Get().LoadModule("WebSockets");
	// }
	// WebSocketPtr = FWebSocketsModule::Get().CreateWebSocket("ws://localhost:8080");
	// WebSocketPtr->Connect();
}
void UCppGameInst::Shutdown()
{
	// if (WebSocketPtr->IsConnected())
	// {
	// 	WebSocketPtr->Close();
	// }
	Super::Shutdown();
}
