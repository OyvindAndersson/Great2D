#include "InputComponent.h"
#include "InputCoreTypes.h"
#include <SDL_keycode.h>
#include <SDL_events.h>


CInputComponent::CInputComponent()
= default;

bool CInputComponent::Initialize()
{
	return true;
}

void CInputComponent::Destroy()
{
}
