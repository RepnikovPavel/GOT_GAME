// Fill out your copyright notice in the Description page of Project Settings.

#include <fstream>


#include "Person.h"

// Sets default values
APerson::APerson()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMeshPtr = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("subobject name - skeletal mesh"));
	
	SkeletalMeshPtr->SetupAttachment(GetRootComponent());
	// skeletal mesh location:
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshSource(TEXT(
		"/Game/MyContent/PersonSource/Lola_B_Styperek"));
	// C:/unreal_engine_projects/MakeAnimPr/Content
	if(SkeletalMeshSource.Succeeded())
	{
		SkeletalMeshPtr->SetSkeletalMesh(SkeletalMeshSource.Object);
		SkeletalMeshPtr->SetRelativeLocation(FVector(0.0,0.0,0.0));
		SkeletalMeshPtr->SetWorldScale3D(FVector(1.0,1.0,1.0));
	}
	else
	{
		std::ofstream MyLogFile;
		MyLogFile.open("C:\\unreal_engine_projects\\MakeAnimPr\\MyLog.txt",std::ios::app);
		MyLogFile << "\nSkeletal Mesh Lola_B_Styperek not loaded\n";
		MyLogFile.close();
	}
	
}

// Called when the game starts or when spawned
void APerson::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APerson::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

