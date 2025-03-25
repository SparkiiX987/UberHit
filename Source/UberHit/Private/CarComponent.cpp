#include "CarComponent.h"

UCarComponent::UCarComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCarComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCarComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (isAccelerating)
	{
		Accelerate(DeltaTime);
	}
	else
	{
		Deccelerate(DeltaTime);
	}
}

void UCarComponent::Accelerate(float DeltaTime)
{
	if (currentSpeed >= maxSpeed)
	{
		currentSpeed = maxSpeed;
		return;
	}
	currentSpeed = currentSpeed + accelerationFactor * DeltaTime;
}

void UCarComponent::Deccelerate(float DeltaTime)
{
	if (currentSpeed <= 0)
	{
		currentSpeed = 0;
		return;
	}
	currentSpeed = currentSpeed - deccelerationFactor * DeltaTime;
}

