// Copyright Fortune Studios 2014-2015. All Rights Reserved.

#pragma once

#include "GameFramework/Character.h"
#include "SOSCharacter.generated.h"

UCLASS()
class SOS_API ASOSCharacter : public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties [6-6-2015 | FortuneMatthew | SOSCharacter.h]
	ASOSCharacter();

	// Input handling for this character [6-6-2015 | FortuneMatthew | SOSCharacter.h]
	virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category = "Rendering")
	// The first person rendering perspective [6-6-2015 | FortuneMatthew | SOSCharacter.h]
	UCameraComponent * FirstPersonCameraComponent;

protected:
	UFUNCTION(BlueprintCallable , Category = "Movement")
	// Move the character forward [6-6-2015 | FortuneMatthew | SOSCharacter.h]
	void MoveForward (float Input);

	UFUNCTION(BlueprintCallable , Category = "Movement")
	// Move the character right [6-6-2015 | FortuneMatthew | SOSCharacter.h]
	void MoveRight(float Input);

private:
	// Handle all the actual movement logic [6-6-2015 | FortuneMatthew | SOSCharacter.h]
	void _move(const float & MoveSpeed , const EAxis::Type & MoveVector);
};
