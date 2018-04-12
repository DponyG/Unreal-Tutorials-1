// Copyright Sam Grenon

#include "Grabber.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "GameFramework/Controller.h"



#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector()* Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
		);


	/*UE_LOG(LogTemp, Warning, TEXT("Location: %s, Position: %s"),
		*PlayerViewPointLocation.ToString(), 
		*PlayerViewPointRotation.ToString());*/

	//TODO Log out to test
	// Get player View point this tick

	// Ray-Cast out to reach distance

	// See what we hit

	// ...
}

