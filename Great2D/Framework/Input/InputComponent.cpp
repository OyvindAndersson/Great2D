#include "InputComponent.h"
#include <SDL_keycode.h>
#include <SDL_events.h>


CInputComponent::CInputComponent()
= default;

CInputComponent::~CInputComponent()
{
	for(auto& ab : ActionBindings)
	{
		ab.Callback = nullptr;
	}
}

bool CInputComponent::Initialize()
{
	KeyStateMap[EKeyCodes::Return] = FKeyState(EKeyCodes::Return, "Return");
	KeyStateMap[EKeyCodes::Esc] = FKeyState(EKeyCodes::Esc, "Escape");
	KeyStateMap[EKeyCodes::Backspace] = FKeyState(EKeyCodes::Backspace, "Backspace");
	KeyStateMap[EKeyCodes::Tab] = FKeyState(EKeyCodes::Tab, "Tab");
	KeyStateMap[EKeyCodes::Space] = FKeyState(EKeyCodes::Space, "Space");
	KeyStateMap[EKeyCodes::Exclaim] = FKeyState(EKeyCodes::Exclaim, "Exclaim");
	KeyStateMap[EKeyCodes::DoubleQuote] = FKeyState(EKeyCodes::DoubleQuote, "DoubleQuote");
	KeyStateMap[EKeyCodes::Hash] = FKeyState(EKeyCodes::Hash, "Hash");
	KeyStateMap[EKeyCodes::Percent] = FKeyState(EKeyCodes::Percent, "Percent");
	KeyStateMap[EKeyCodes::Dollar] = FKeyState(EKeyCodes::Dollar, "Dollar");
	KeyStateMap[EKeyCodes::Amp] = FKeyState(EKeyCodes::Amp, "Amp");
	KeyStateMap[EKeyCodes::Quote] = FKeyState(EKeyCodes::Quote, "Quote");
	KeyStateMap[EKeyCodes::LeftParen] = FKeyState(EKeyCodes::LeftParen, "LeftParen");
	KeyStateMap[EKeyCodes::RightParen] = FKeyState(EKeyCodes::RightParen, "RightParen");
	KeyStateMap[EKeyCodes::Asterisk] = FKeyState(EKeyCodes::Asterisk, "Asterisk");
	KeyStateMap[EKeyCodes::Plus] = FKeyState(EKeyCodes::Plus, "Plus");
	KeyStateMap[EKeyCodes::Comma] = FKeyState(EKeyCodes::Comma, "Comma");
	KeyStateMap[EKeyCodes::Minus] = FKeyState(EKeyCodes::Minus, "Minus");
	KeyStateMap[EKeyCodes::Period] = FKeyState(EKeyCodes::Period, "Period");
	KeyStateMap[EKeyCodes::Slash] = FKeyState(EKeyCodes::Slash, "Slash");
	KeyStateMap[EKeyCodes::Zero] = FKeyState(EKeyCodes::Zero, "0");
	KeyStateMap[EKeyCodes::One] = FKeyState(EKeyCodes::One, "1");
	KeyStateMap[EKeyCodes::Two] = FKeyState(EKeyCodes::Two, "2");
	KeyStateMap[EKeyCodes::Three] = FKeyState(EKeyCodes::Three, "3");
	KeyStateMap[EKeyCodes::Four] = FKeyState(EKeyCodes::Four, "4");
	KeyStateMap[EKeyCodes::Five] = FKeyState(EKeyCodes::Five, "5");
	KeyStateMap[EKeyCodes::Six] = FKeyState(EKeyCodes::Six, "6");
	KeyStateMap[EKeyCodes::Seven] = FKeyState(EKeyCodes::Seven, "7");
	KeyStateMap[EKeyCodes::Eight] = FKeyState(EKeyCodes::Eight, "8");
	KeyStateMap[EKeyCodes::Nine] = FKeyState(EKeyCodes::Nine, "9");
	KeyStateMap[EKeyCodes::Colon] = FKeyState(EKeyCodes::Colon, ":");
	KeyStateMap[EKeyCodes::SemiColon] = FKeyState(EKeyCodes::SemiColon, ";");
	KeyStateMap[EKeyCodes::Less] = FKeyState(EKeyCodes::Less, "<");
	KeyStateMap[EKeyCodes::Equals] = FKeyState(EKeyCodes::Equals, "=");
	KeyStateMap[EKeyCodes::Greater] = FKeyState(EKeyCodes::Greater, ">");
	KeyStateMap[EKeyCodes::Question] = FKeyState(EKeyCodes::Question, "?");
	KeyStateMap[EKeyCodes::At] = FKeyState(EKeyCodes::At, "@");
	KeyStateMap[EKeyCodes::LeftBracket] = FKeyState(EKeyCodes::LeftBracket, "[");
	KeyStateMap[EKeyCodes::Backslash] = FKeyState(EKeyCodes::Backslash, "\\");
	KeyStateMap[EKeyCodes::RightBracket] = FKeyState(EKeyCodes::RightBracket, "]");
	KeyStateMap[EKeyCodes::Caret] = FKeyState(EKeyCodes::Caret, "^");
	KeyStateMap[EKeyCodes::Underscore] = FKeyState(EKeyCodes::Underscore, "_");
	KeyStateMap[EKeyCodes::Backquote] = FKeyState(EKeyCodes::Backquote, "\"");
	
	KeyStateMap[EKeyCodes::A] = FKeyState(EKeyCodes::A, "A");
	KeyStateMap[EKeyCodes::B] = FKeyState(EKeyCodes::B, "B");
	KeyStateMap[EKeyCodes::C] = FKeyState(EKeyCodes::C, "C");
	KeyStateMap[EKeyCodes::D] = FKeyState(EKeyCodes::D, "D");
	KeyStateMap[EKeyCodes::E] = FKeyState(EKeyCodes::E, "E");
	KeyStateMap[EKeyCodes::F] = FKeyState(EKeyCodes::F, "F");
	KeyStateMap[EKeyCodes::G] = FKeyState(EKeyCodes::G, "G");
	KeyStateMap[EKeyCodes::H] = FKeyState(EKeyCodes::H, "H");
	KeyStateMap[EKeyCodes::I] = FKeyState(EKeyCodes::I, "I");
	KeyStateMap[EKeyCodes::J] = FKeyState(EKeyCodes::J, "J");
	KeyStateMap[EKeyCodes::K] = FKeyState(EKeyCodes::K, "K");
	KeyStateMap[EKeyCodes::L] = FKeyState(EKeyCodes::L, "L");
	KeyStateMap[EKeyCodes::M ] = FKeyState(EKeyCodes::M, "M");
	KeyStateMap[EKeyCodes::N] = FKeyState(EKeyCodes::N, "N");
	KeyStateMap[EKeyCodes::Q] = FKeyState(EKeyCodes::Q, "Q");
	KeyStateMap[EKeyCodes::R] = FKeyState(EKeyCodes::R, "R");
	KeyStateMap[EKeyCodes::S] = FKeyState(EKeyCodes::S, "S");
	KeyStateMap[EKeyCodes::T] = FKeyState(EKeyCodes::T, "T");
	KeyStateMap[EKeyCodes::U] = FKeyState(EKeyCodes::U, "U");
	KeyStateMap[EKeyCodes::V] = FKeyState(EKeyCodes::V, "V");
	KeyStateMap[EKeyCodes::W] = FKeyState(EKeyCodes::W, "W");
	KeyStateMap[EKeyCodes::X] = FKeyState(EKeyCodes::X, "X");
	KeyStateMap[EKeyCodes::Y] = FKeyState(EKeyCodes::Y, "Y");
	KeyStateMap[EKeyCodes::Z] = FKeyState(EKeyCodes::Z, "Z");

	KeyStateMap[EKeyCodes::CapsLock] = FKeyState(EKeyCodes::CapsLock, "CapsLock");
	KeyStateMap[EKeyCodes::F1] = FKeyState(EKeyCodes::F1, "F1");
	KeyStateMap[EKeyCodes::F2] = FKeyState(EKeyCodes::F2, "F2");
	KeyStateMap[EKeyCodes::F3] = FKeyState(EKeyCodes::F3, "F3");
	KeyStateMap[EKeyCodes::F4] = FKeyState(EKeyCodes::F4, "F4");
	KeyStateMap[EKeyCodes::F5] = FKeyState(EKeyCodes::F5, "F5");
	KeyStateMap[EKeyCodes::F6] = FKeyState(EKeyCodes::F6, "F6");
	KeyStateMap[EKeyCodes::F7] = FKeyState(EKeyCodes::F7, "F7");
	KeyStateMap[EKeyCodes::F8] = FKeyState(EKeyCodes::F8, "F8");
	KeyStateMap[EKeyCodes::F9] = FKeyState(EKeyCodes::F9, "F9");
	KeyStateMap[EKeyCodes::F10] = FKeyState(EKeyCodes::F10, "F10");
	KeyStateMap[EKeyCodes::F11] = FKeyState(EKeyCodes::F11, "F11");
	KeyStateMap[EKeyCodes::F12] = FKeyState(EKeyCodes::F12, "F12");
	KeyStateMap[EKeyCodes::PrintScreen] = FKeyState(EKeyCodes::PrintScreen, "Print Screen");
	KeyStateMap[EKeyCodes::ScrollLock] = FKeyState(EKeyCodes::ScrollLock, "Scroll Lock");
	KeyStateMap[EKeyCodes::Pause] = FKeyState(EKeyCodes::Pause, "Pause");
	KeyStateMap[EKeyCodes::Insert] = FKeyState(EKeyCodes::Insert, "Insert");
	KeyStateMap[EKeyCodes::Home] = FKeyState(EKeyCodes::Home, "Home");
	KeyStateMap[EKeyCodes::PageUp] = FKeyState(EKeyCodes::PageUp, "PageUp");
	KeyStateMap[EKeyCodes::Delete] = FKeyState(EKeyCodes::Delete, "Delete");
	KeyStateMap[EKeyCodes::End] = FKeyState(EKeyCodes::End, "End");
	KeyStateMap[EKeyCodes::PageDown] = FKeyState(EKeyCodes::PageDown, "PageDown");
	
	KeyStateMap[EKeyCodes::Right] = FKeyState(EKeyCodes::Right, "Right");
	KeyStateMap[EKeyCodes::Left] = FKeyState(EKeyCodes::Left, "Left");
	KeyStateMap[EKeyCodes::Down] = FKeyState(EKeyCodes::Down, "Down");
	KeyStateMap[EKeyCodes::Up] = FKeyState(EKeyCodes::Up, "Up");

	KeyStateMap[EKeyCodes::NumLockClear] = FKeyState(EKeyCodes::NumLockClear, "Num Lock Clear");
	KeyStateMap[EKeyCodes::KeyPadDivide] = FKeyState(EKeyCodes::KeyPadDivide, "Keypad Divide");
	KeyStateMap[EKeyCodes::KeyPadMultiply] = FKeyState(EKeyCodes::KeyPadMultiply, "Keypad Multiply");
	KeyStateMap[EKeyCodes::KeyPadMinus] = FKeyState(EKeyCodes::KeyPadMinus, "Keypad Minus");
	KeyStateMap[EKeyCodes::KeyPadPlus] = FKeyState(EKeyCodes::KeyPadPlus, "Keypad Plus");
	KeyStateMap[EKeyCodes::KeyPadEnter] = FKeyState(EKeyCodes::KeyPadEnter, "Keypad Enter");
	KeyStateMap[EKeyCodes::KeyPad_1] = FKeyState(EKeyCodes::KeyPad_1, "Keypad 1");
	KeyStateMap[EKeyCodes::KeyPad_2] = FKeyState(EKeyCodes::KeyPad_2, "Keypad 2");
	KeyStateMap[EKeyCodes::KeyPad_3] = FKeyState(EKeyCodes::KeyPad_3, "Keypad 3");
	KeyStateMap[EKeyCodes::KeyPad_4] = FKeyState(EKeyCodes::KeyPad_4, "Keypad 4");
	KeyStateMap[EKeyCodes::KeyPad_5] = FKeyState(EKeyCodes::KeyPad_5, "Keypad 5");
	KeyStateMap[EKeyCodes::KeyPad_6] = FKeyState(EKeyCodes::KeyPad_6, "Keypad 6");
	KeyStateMap[EKeyCodes::KeyPad_7] = FKeyState(EKeyCodes::KeyPad_7, "Keypad 7");
	KeyStateMap[EKeyCodes::KeyPad_8] = FKeyState(EKeyCodes::KeyPad_8, "Keypad 8");
	KeyStateMap[EKeyCodes::KeyPad_9] = FKeyState(EKeyCodes::KeyPad_9, "Keypad 9");
	KeyStateMap[EKeyCodes::KeyPad_0] = FKeyState(EKeyCodes::KeyPad_0, "Keypad 0");
	KeyStateMap[EKeyCodes::KeyPadPeriod] = FKeyState(EKeyCodes::KeyPadPeriod, "Keypad ,");

	KeyStateMap[EKeyCodes::RightShift] = FKeyState(EKeyCodes::RightShift, "Right Shift");
	KeyStateMap[EKeyCodes::LeftShift] = FKeyState(EKeyCodes::LeftShift, "Left Shift");
	KeyStateMap[EKeyCodes::RightAlt] = FKeyState(EKeyCodes::RightAlt, "Right Alt");
	KeyStateMap[EKeyCodes::LeftAlt] = FKeyState(EKeyCodes::LeftAlt, "Left Alt");
	KeyStateMap[EKeyCodes::LeftGui] = FKeyState(EKeyCodes::LeftGui, "Left Win");
	KeyStateMap[EKeyCodes::RightGui] = FKeyState(EKeyCodes::RightGui, "Right Win");
	
	return true;
}

void CInputComponent::Destroy()
{
}

void CInputComponent::HandleInputEvents(SDL_Event InEvent)
{
	if(InEvent.type == SDL_KEYUP)
	{
		SDL_Keycode code = InEvent.key.keysym.sym;
	}
	else if(InEvent.type == SDL_KEYDOWN)
	{
		
	}
	else if(InEvent.type == SDL_MOUSEMOTION || InEvent.type == SDL_JOYAXISMOTION)
	{
		
	}
}

void CInputComponent::GetAllInputs(std::vector<FKeyState>& OutAllKeys)
{
	for(const auto &v : KeyStateMap)
	{
		OutAllKeys.push_back(v.second);
	}
}

FKeyState* CInputComponent::GetKeyState(EKeyCodes Key)
{
	FKeyState* State = &KeyStateMap[Key];

	return State;
}

void CInputComponent::BindAction(EInputEvent InInputEvent, EKeyCodes InKey, std::function<void()> Callback)
{
	if( Callback == nullptr)
	{
		return;
	}

	FActionBinding NewBinding(InInputEvent, InKey, Callback);
	
	ActionBindings.push_back(NewBinding);
}


/*************************************************
 * FActionBinding
 */

void FActionBinding::Execute()
{
	if(Callback != nullptr)
	{
		Callback();
	}
}


/*
 *FKeyState* State = nullptr;
	
	switch(InEvent.type)
	{
	case SDL_KEYDOWN:
		State = &KeyStateMap[(EKeyCodes)InEvent.key.keysym.sym];
		if(State)
		{
			if(State->bIsDown)
			{
				break;
			}
			
			State->AccumulatedEvents->push_back(InEvent);
			State->bIsDown = true;
			State->InputState = EInputEvent::IE_Pressed;
		}

		//printf_s("Key %s DOWN\n", State->DisplayName.c_str());
		break;

	case SDL_KEYUP:
		State = &KeyStateMap[(EKeyCodes)InEvent.key.keysym.sym];
		if (State)
		{
			State->AccumulatedEvents->push_back(InEvent);
			State->bPreviousDown = false;
			State->bIsDown = false;
			State->InputState = EInputEvent::IE_Released;
		}
		//printf_s("Key %s UP\n", State->DisplayName.c_str());
		
		break;

	case SDL_MOUSEMOTION:
		
		//printf_s("Mouse X=%i, Y=%i\n", InEvent.motion.x, InEvent.motion.y);
		break;

	case SDL_MOUSEBUTTONDOWN:
		//printf_s("Mouse button down\n");
		break;

	case SDL_MOUSEBUTTONUP:
		//printf_s("Mouse button up\n");
		break;

	case SDL_MOUSEWHEEL:
		//printf_s("Mouse scroll\n");
		break;

	default:
		break;
	}

	// Handle action bindings

	if(State)
	{
		if(State->AccumulatedEvents->size() >= IE_MAX)
		{
			State->AccumulatedEvents->pop_back();
		}
		for (auto& ab : ActionBindings)
		{
			// Fire any action bindings that matches input state and key
			if(ab.InputEvent == State->InputState && ab.Key == State->Key)
			{
				ab.Execute();
				int32_t x = State->AccumulatedEvents->size();
				printf_s("Event accum: %i", x);
			}
		}
	}
 * 
 */