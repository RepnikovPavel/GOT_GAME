// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPerson.h"

// Sets default values
AMyPerson::AMyPerson()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetSkelatalMesh();
}

// Called when the game starts or when spawned
void AMyPerson::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPerson::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



// Ctor functions:
void AMyPerson::SetSkelatalMesh()
{
	SkeletalMeshComponentPtr = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("subobject name - skeletal mesh component"));
	SkeletalMeshComponentPtr->SetupAttachment(GetRootComponent());

	//// loading  skeletal mesh from disk
	// static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshFinder(
	// 	TEXT("/Game/MyContent/knight/model/"));
	//
	// if (SkeletalMeshFinder.Succeeded())
	// {
	// 	SkeletalMeshComponentPtr->SetSkeletalMesh(SkeletalMeshFinder.Object);
	// 	SkeletalMeshComponentPtr->SetRelativeLocation(FVector(0.0,0.0,0.0));
	// 	SkeletalMeshComponentPtr->SetWorldScale3D(FVector(1.0,1.0,1.0));
	// }
	// else
	// {
	// 	if(GEngine)
	// 	{
	// 		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,"cannont load skeletal mesh");
	// 	}
	// }
}

void AMyPerson::PlayAnimation()
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
