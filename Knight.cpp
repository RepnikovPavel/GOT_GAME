// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"

// Sets default values
AKnight::AKnight()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetSkelatalMeshComponent();
	SetPhysAssetToSkeletalMesh();
	SetSettingsToSkelatalMeshComponent();
}

// Called when the game starts or when spawned
void AKnight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKnight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKnight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Ctor functions:
void AKnight::SetSkelatalMeshComponent()
{
	SkeletalMeshComponentPtr = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("subobject name - skeletal mesh component"));
	SkeletalMeshComponentPtr->SetupAttachment(GetRootComponent());
	
}
void AKnight::SetPhysAssetToSkeletalMesh()
{
	//// loading  phys asset from disk
	static ConstructorHelpers::FObjectFinder<UPhysicsAsset> Finder(PathToPhysicsAsset);
	
	if (Finder.Succeeded())
	{
		SkeletalMeshComponentPtr->SetPhysicsAsset(Finder.Object);
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,"PA set was successful");
		}
	}
	else
	{
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,"PA set was unsuccessful");
		}
	}

	// 
}
void AKnight::SetSettingsToSkelatalMeshComponent()
{
	// here need set "Collision Presets" to "Pawn" in "Skeletal Mesh Component Ptr" in blueprint
}
// Callbacks:
void AKnight::PlayAnimation()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,"1 button pressed");
	}
	if (AnimationAssetPtr)
	{
		SkeletalMeshComponentPtr->PlayAnimation(AnimationAssetPtr,true);
	}
}
void AKnight::PlayPhysicalAnimation()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,"2 button pressed");
	}
	SkeletalMeshComponentPtr->SetAllBodiesBelowSimulatePhysics(HipsBone,true,false);
}

