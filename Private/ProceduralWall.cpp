// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralWall.h"
#include <random>
#include <StructuredQueryCondition.h>


// Sets default values
AProceduralWall::AProceduralWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MeshComponentPtr = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	MeshComponentPtr->SetupAttachment(GetRootComponent());
}

void AProceduralWall::Generator()
{
	const float TotalArea = Width*Height;
	const float XStep = Width/(NumOfVertexesX-1);
	const float YStep = Height/(NumOfVertexesY-1);

	//here we can make or read grids of x and y and z arr
	//...
	//
	
	// make grid, z=0.0 as default value
	// for example make z random
	std::random_device RD;
	std::mt19937 MT(RD());
	std::uniform_real_distribution<double> UniformDistribution(MaxDepth, 0);

	// tutorial can see there http://www.songho.ca/opengl/gl_vbo.html
	
	//make vertexes from ij array of depth
	for(size_t i=0;i<NumOfVertexesX;i++)
	{
		for(size_t j=0;j<NumOfVertexesY;j++)
		{
			//UniformDistribution(MT)
			//or 0.0
			//or any f(x,y)
			//or you can use diamond square alg (but need 2^N+1 vertex along x and 2^N+1 vertex along y only)
			Vertexes.Add(FVector(i*XStep,j*YStep,UniformDistribution(MT)));
		}
	}
	//make UV
	for(size_t i=0;i<NumOfVertexesX;i++)
	{
		for(size_t j=0;j<NumOfVertexesY;j++)
		{
			UV0.Add(FVector2D(i*XStep*UVScaleAlongX,j*YStep*UVScaleAlongY));
		}
	}
	
	
	// make list of indexes for making triangles
	// проход по квадратам слева направо при j=k затем повторяется для следюузего j=k+1
	for(size_t j=0;j<NumOfVertexesY-1;j++)
	{
		for(size_t i=0;i<NumOfVertexesX-1;i++)
		{
			//  v1------v0   
			//  |       |    
			//  |       |  
			//  |       |
			//  v2------v3
			
			// //counterclockwise
			// // v0-v1-v2
			// TrianglesIndexes.Add((i+1)*NumOfVertexesY+1 +j);
			// TrianglesIndexes.Add(i*NumOfVertexesY+1 +j);
			// TrianglesIndexes.Add(i*NumOfVertexesY +j);
			// //v2-v3-v0
			// TrianglesIndexes.Add(i*NumOfVertexesY +j);
			// TrianglesIndexes.Add((i+1)*NumOfVertexesY +j);
			// TrianglesIndexes.Add((i+1)*NumOfVertexesY+1 +j);
			// clockwise
			// v0-v3-v2
			TrianglesIndexes.Add((i+1)*NumOfVertexesY+1 +j);
			TrianglesIndexes.Add((i+1)*NumOfVertexesY +j);
			TrianglesIndexes.Add(i*NumOfVertexesY +j);
			//v2-v1-v0
			TrianglesIndexes.Add(i*NumOfVertexesY +j);
			TrianglesIndexes.Add(i*NumOfVertexesY+1 +j);
			TrianglesIndexes.Add((i+1)*NumOfVertexesY+1 +j);
		}
	}
	
}


// Called when the game starts or when spawned
void AProceduralWall::BeginPlay()
{
	Super::BeginPlay();
	Generator();
	MeshComponentPtr->CreateMeshSection(0,Vertexes,TrianglesIndexes,TArray<FVector>(),UV0,TArray<FColor>(),TArray<FProcMeshTangent>(),true);
	MeshComponentPtr->SetMaterial(0,Material);
}
// Called every frame
void AProceduralWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

