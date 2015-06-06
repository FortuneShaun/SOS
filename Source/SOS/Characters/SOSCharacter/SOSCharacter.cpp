// Copyright Fortune Studios 2014-2015. All Rights Reserved.

#include "SOS.h"
#include "SOSCharacter.h"

// Sets default values for this character's properties [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
ASOSCharacter::ASOSCharacter() {
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>("FirstPersonCameraComponent");

	if (FirstPersonCameraComponent) {
		FirstPersonCameraComponent->bUsePawnControlRotation = true;
		FirstPersonCameraComponent->AttachParent = GetRootComponent();
		FirstPersonCameraComponent->SetRelativeLocation(FVector(0 , 0 , BaseEyeHeight + 15));
	}
}

// Input handling for this character [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
void ASOSCharacter::SetupPlayerInputComponent(class UInputComponent * InputComponent) {
	if (InputComponent) {
		// Default key bindings [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
		InputComponent->BindAxis("MoveForward" , this , &ASOSCharacter::MoveForward);
		InputComponent->BindAxis("MoveRight" , this , &ASOSCharacter::MoveRight);
		
		// Default mouse bindings [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
		InputComponent->BindAxis("Mouse_LookUp" , this , &ASOSCharacter::AddControllerPitchInput);
		InputComponent->BindAxis("Mouse_Turn" , this , &ASOSCharacter::AddControllerYawInput);
	}
}

// Move the character forward [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
void ASOSCharacter::MoveForward(float Input) {
	_move(Input , EAxis::X);
}

// Move the character right [6-6-2015 | FortuneMatthew | SOSCharacter.h]
void ASOSCharacter::MoveRight(float Input) {
	_move(Input , EAxis::Y);
}

// Handle all the actual movement logic [6-6-2015 | FortuneMatthew | SOSCharacter.h]
void ASOSCharacter::_move(const float & MoveSpeed , const EAxis::Type & MoveVector) {
	// Get the rotation of the controller [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
	FRotator Rotation = GetControlRotation();

	// If we are falling || If we are moving [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
	if (GetCharacterMovement()->IsFalling() || GetCharacterMovement()->IsMovingOnGround()) {
		// Remove vertical movement [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
		Rotation.Pitch = 0.0f;
	}

	// Get the vector that the character should move to [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
	FVector MoveVec = FRotationMatrix(Rotation).GetScaledAxis(MoveVector);
	// Move using the direction we found and the impulse provided by the function call [6-6-2015 | FortuneMatthew | SOSCharacter.cpp]
	AddMovementInput(MoveVec , MoveSpeed);
}
