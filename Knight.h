// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Knight.generated.h"


inline const auto PathToPhysicsAsset = TEXT("/Game/MyContent/knight/model/armed_knight_PhysicsMyAsset");
inline const auto HipsBone = TEXT("Hips");
// instructions:
// go to SetSettingsToSkelatalMeshComponent and read

UCLASS()
class MYPROJECT_API AKnight : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKnight();

public:
	// Components:
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMeshComponentPtr;
	
	// Assets:
	UPROPERTY(EditDefaultsOnly,Category="Animations")
	UAnimationAsset* AnimationAssetPtr; 	


	
	
	//Callbacks
	UFUNCTION(BlueprintCallable)
	void PlayAnimation();

	UFUNCTION(BlueprintCallable)
	void PlayPhysicalAnimation();
	
private:
	// Ctor Functions:
	void SetSkelatalMeshComponent();
	void SetPhysAssetToSkeletalMesh();
	void SetSettingsToSkelatalMeshComponent();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
