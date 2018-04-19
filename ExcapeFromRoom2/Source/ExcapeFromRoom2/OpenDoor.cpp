// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include <Components/PrimitiveComponent.h>


#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();


	// ...
	
}

void UOpenDoor::OpenDoor() {
	Owner->SetActorRotation(FRotator(0.f, -90.0f, 0.f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GetTotalMassOfActorsOnPlate() > 10.f) {
		OpenDoor();
		TimeSinceDoorClose = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - TimeSinceDoorClose > DoorCloseTimer)
		CloseDoor();

	// ...
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {
	float TotalMass = 0.f;
	//Find all overlapping actors
	//Iterate through them adding their masses
	TArray<AActor*> OverlappingActors;

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for(auto & Actors : OverlappingActors) {
		TotalMass += Actors->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		
		//UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), TotalMass);
	}

	return TotalMass;

}

