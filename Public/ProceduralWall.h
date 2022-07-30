// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Chaos/Vector.h"
#include "ProceduralWall.generated.h"

UCLASS()
class MYPROJECT_API AProceduralWall : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float Width=10000;
	UPROPERTY(EditAnywhere)
	float Height=1000;
	UPROPERTY(EditAnywhere)
	float MaxDepth = -100; // максимальная глубина одной щели
	UPROPERTY(EditAnywhere)
	float NumOfVertexesX =  64; // число вершин по оси x
	UPROPERTY(EditAnywhere)
	float NumOfVertexesY = 64; // число вершин по оси y
	UPROPERTY(EditAnywhere)
	float UVScaleAlongX = 1; // число вершин по оси y
	UPROPERTY(EditAnywhere)
	float UVScaleAlongY = 1; // число вершин по оси y
	
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;
	
public:	
	// Sets default values for this actor's properties
	AProceduralWall();
	
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* MeshComponentPtr;

private:
	//making one gap
	TArray<FVector> Vertexes;
	TArray<int> TrianglesIndexes;
	TArray<FVector2D> UV0;
	void Generator();
	 
	

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
