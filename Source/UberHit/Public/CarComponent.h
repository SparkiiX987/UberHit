#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CarComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UBERHIT_API UCarComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCarComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Car")
	float currentSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Car")
	float accelerationFactor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Car")
	float maxSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Car")
	float deccelerationFactor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Car")
	bool isAccelerating;

	UFUNCTION(BlueprintCallable, Category = "Car")
	void Accelerate(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Car")
	void Deccelerate(float DeltaTime);
		
};
