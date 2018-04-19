// Copyright Sam Grenon

#include "Grabber.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "GameFramework/Controller.h"
#include <CollisionQueryParams.h>
#include <Components/InputComponent.h>

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

	FindPhysicsComponent();
	SetupInputComponent();


	// ...

}

//Find the Physics Component
void UGrabber::FindPhysicsComponent() {
	///Look for attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	
	if (PhysicsHandle== nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Could not find physics handle"));
	}
	

}

//Sets up the InputHandle
void UGrabber::SetupInputComponent() {
	InputHandle = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputHandle) {
		//Bind the input axis.
		InputHandle->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputHandle->BindAction("Grab", IE_Released, this, &UGrabber::Released);
	}

	else {
		UE_LOG(LogTemp, Error, TEXT("Could not find InputHandle: %s"), *GetOwner()->GetName());
	}
}

void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Atempting to Grab"));
	//Line Trace to reach any actors with physics body collision channel set
	//If we hit something then attatch a physics handle.
	auto HitResult = FindPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();
	if (ActorHit) {
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true
		);
	}
}

void UGrabber::Released() {
	PhysicsHandle->ReleaseComponent();
	UE_LOG(LogTemp, Warning, TEXT("Atempting to release"));
	//Todo released physics
}

FVector UGrabber::GetReachLineStart() {
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation;

}

FVector UGrabber::GetReachLineEnd() {
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector()* Reach;

}


//Shoots out a ray-cast to see if we are in reach of a movable object.
const FHitResult UGrabber::FindPhysicsBodyInReach()
{

	// Set query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	/// Line Trace (aka ray-cast) out to each distance
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(

		OUT HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters

	);

	return HitResult;
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//if physics handle is attatched move whats holding.

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}

}
