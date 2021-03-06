// Fill out your copyright notice in the Description page of Project Settings.

#include "Goal.h"


// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	// goalMeshCompのオーバーラップイベントにデリゲート関数をバインドする
	goalMeshComp->OnComponentBeginOverlap.AddDynamic(this, &AGoal::BeginOverlap);
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// オーバーラップイベントで実行するデリゲート
void AGoal::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	// 現時点ではデバッグ出力するのみ
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, "GOAL!!!");
}
