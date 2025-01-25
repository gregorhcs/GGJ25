// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionTile.h"

#include "PlayerSink.h"


ACollisionTile::ACollisionTile()
{
	PrimaryActorTick.bCanEverTick = true;

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	SetRootComponent(Plane);
}

void ACollisionTile::SetSize(float Size)
{
	SetActorRelativeScale3D(FVector(Size));
}

// Called when the game starts or when spawned
void ACollisionTile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollisionTile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (!Cast<APlayerSink>(OtherActor))
		return;

	Plane->SetCollisionProfileName(TEXT("BlockNoneOverlapPawn"));
}

void ACollisionTile::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (!Cast<APlayerSink>(OtherActor))
		return;

	Plane->SetCollisionProfileName(TEXT("BlockAllOverlapPawn"));
}
