#include "PlayerController.h"
#include "../../Framework/Input/InputComponent.h"

void APlayerController::SetupPlayerInputs(CInputComponent* InputComponent)
{
	std::vector<FKeyState> KeyStates;
	InputComponent->GetAllInputs(KeyStates);

	InputComponent->BindAction(IE_Pressed, EKeyCodes::Up, std::bind(&APlayerController::StartMove, this));
	InputComponent->BindAction(IE_Released, EKeyCodes::Up, std::bind(&APlayerController::StopMove, this));
}

void APlayerController::StartMove()
{
	printf_s("APlayerController::StartMove\n");

	bIsMoving = true;
}

void APlayerController::StopMove()
{
	printf_s("APlayerController::StopMove\n");

	bIsMoving = false;
}