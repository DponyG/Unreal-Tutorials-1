// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <PhysicsEngine/PhysicsHandleComponent.h>
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXCAPEFROMROOM2_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;
	UPhysicsHandleComponent * PhysicsHandle = nullptr;
	UInputComponent * InputHandle = nullptr;

	// Ray-Cast and grab whats in reach
	void Grab();

	//Release whats grabbed
	void Released();

	//Find the attatched physics handle
	void FindPhysicsComponent();
	//Find the attatched input handle
	void SetupInputComponent();

	//Returns the end of the Reach
	FVector GetReachLineEnd();

	FVector GetReachLineStart();

	//Return hit for first physics body in reach
	const FHitResult FindPhysicsBodyInReach();

		
	
};
