// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPerson.generated.h"

UCLASS()
class MYPROJECT_API AMyPerson : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPerson();
public:
	// Components:
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMeshComponentPtr;

	// Assets:
	UPROPERTY(EditDefaultsOnly,Category="Animations")
	UAnimationAsset* AnimationAssetPtr; 	

	
	//Actions from keyboard events
	UFUNCTION(BlueprintCallable)
	void PlayAnimation();
	
private:
	// Ctor Functions:
	void SetSkelatalMesh();
	
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
