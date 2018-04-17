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

	///Look for attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	InputHandle = GetOwner()->FindComponentByClass<UInputComponent>();
	if (PhysicsHandle) {
		//Physics handle is found
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Could not find: %s"), *GetOwner()->GetName());
	}

	if (InputHandle) {
		//Bind the input axis.
		InputHandle->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	}
		
	else {
		UE_LOG(LogTemp, Error, TEXT("Could not find InputHandle: %s"), *GetOwner()->GetName());
	}


	// ...

}

void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Atempting to Grab"));
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


	// Set query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	/// Line Trace (aka ray-cast) out to each distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(

		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters

	);


	AActor * ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *(ActorHit->GetName()));
	}

	

}
