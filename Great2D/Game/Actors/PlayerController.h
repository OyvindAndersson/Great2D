#pragma once
#include "GameActor.h"

class APlayerController : public AGameActor
{
public:

	void SetupPlayerInputs(class CInputComponent* InputComponent);

	void StartMove();
	void StopMove();

protected:

	bool bIsMoving = false;
};

