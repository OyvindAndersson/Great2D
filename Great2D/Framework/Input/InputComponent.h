#pragma once

#include <functional>
#include <unordered_map>
#include <memory>
#include <SDL_keycode.h>
#include <SDL_events.h>

#include "../Application/ISystemComponent.h"
#include "../Core.h"

/**
 * What state a key is in during an event
 */
enum EInputEvent
{
	IE_Pressed		= 0,
	IE_Released		= 1,
	IE_Repeat		= 2,
	IE_DoubleClick	= 3,
	IE_Axis			= 4,
	IE_MAX			= 5
};

/**
 * Key code mapping
 */
enum class EKeyCodes
{
	Invalid			= SDLK_UNKNOWN,
	Return			= SDLK_RETURN,
	Esc				= SDLK_ESCAPE,
	Backspace		= SDLK_BACKSPACE,
	Tab				= SDLK_TAB,
    Space			= SDLK_SPACE,
    Exclaim			= SDLK_EXCLAIM,
    DoubleQuote		= SDLK_QUOTEDBL ,
    Hash			= SDLK_HASH ,
    Percent			= SDLK_PERCENT,
    Dollar			= SDLK_DOLLAR,
    Amp				= SDLK_AMPERSAND,
    Quote			= SDLK_QUOTE,
    LeftParen		= SDLK_LEFTPAREN,
    RightParen		= SDLK_RIGHTPAREN,
    Asterisk		= SDLK_ASTERISK,
    Plus			= SDLK_PLUS,
    Comma			= SDLK_COMMA,
    Minus			= SDLK_MINUS,
    Period			= SDLK_PERIOD,
    Slash			= SDLK_SLASH,
    Zero			= SDLK_0,
    One				= SDLK_1,
    Two				= SDLK_2,
    Three			= SDLK_3,
    Four			= SDLK_4,
    Five			= SDLK_5,
    Six				= SDLK_6,
    Seven			= SDLK_7,
    Eight			= SDLK_8,
    Nine			= SDLK_9,
    Colon			= SDLK_COLON,
    SemiColon		= SDLK_SEMICOLON,
    Less			= SDLK_LESS,
    Equals			= SDLK_EQUALS,
    Greater			= SDLK_GREATER,
    Question		= SDLK_QUESTION,
    At				= SDLK_AT,

	LeftBracket		= SDLK_LEFTBRACKET,
	Backslash		= SDLK_BACKSLASH,
	RightBracket	= SDLK_RIGHTBRACKET,
	Caret			= SDLK_CARET,
	Underscore		= SDLK_UNDERSCORE,
	Backquote		= SDLK_BACKQUOTE,

	
	A = SDLK_a,
	B = SDLK_b,
	C = SDLK_c,
	D = SDLK_d,
	E = SDLK_e,
	F = SDLK_f,
	G = SDLK_g,
	H = SDLK_h,
	I = SDLK_i,
	J = SDLK_j,
	K = SDLK_k,
	L = SDLK_l,
	M = SDLK_m,
	N = SDLK_n,
	O = SDLK_o,
	P = SDLK_p,
	Q = SDLK_q,
	R = SDLK_r,
	S = SDLK_s,
	T = SDLK_t,
	U = SDLK_u,
	V = SDLK_v,
	W = SDLK_w,
	X = SDLK_x,
	Y = SDLK_y,
    Z = SDLK_z,

	CapsLock = SDLK_CAPSLOCK,

	F1 = SDLK_F1,
	F2 = SDLK_F2,
	F3 = SDLK_F3,
	F4 = SDLK_F4,
	F5 = SDLK_F5,
	F6 = SDLK_F6,
	F7 = SDLK_F7,
	F8 = SDLK_F8,
	F9 = SDLK_F9,
	F10 = SDLK_F10,
	F11 = SDLK_F11,
	F12 = SDLK_F12,

	PrintScreen = SDLK_PRINTSCREEN,
	ScrollLock = SDLK_SCROLLLOCK,
	Pause = SDLK_PAUSE,
	Insert = SDLK_INSERT,
	Home = SDLK_HOME,
	PageUp = SDLK_PAGEUP,
	Delete = SDLK_DELETE,
	End = SDLK_END,
	PageDown = SDLK_PAGEDOWN,
	Right = SDLK_RIGHT,
	Left = SDLK_LEFT,
	Down = SDLK_DOWN,
	Up = SDLK_UP,

	NumLockClear = SDLK_NUMLOCKCLEAR,
	KeyPadDivide = SDLK_KP_DIVIDE,
	KeyPadMultiply = SDLK_KP_MULTIPLY,
	KeyPadMinus = SDLK_KP_MINUS,
	KeyPadPlus = SDLK_KP_PLUS,
	KeyPadEnter = SDLK_KP_ENTER,
	KeyPad_1 = SDLK_KP_1,
	KeyPad_2 = SDLK_KP_2,
	KeyPad_3 = SDLK_KP_3,
	KeyPad_4 = SDLK_KP_4,
	KeyPad_5 = SDLK_KP_5,
	KeyPad_6 = SDLK_KP_6,
	KeyPad_7 = SDLK_KP_7,
	KeyPad_8 = SDLK_KP_8,
	KeyPad_9 = SDLK_KP_9,
	KeyPad_0 = SDLK_KP_0,
	KeyPadPeriod = SDLK_KP_PERIOD,

	RightShift = SDLK_RSHIFT,
	LeftShift = SDLK_LSHIFT,
	RightAlt = SDLK_RALT,
	LeftAlt = SDLK_LALT,
	LeftGui = SDLK_LGUI,
	RightGui = SDLK_RGUI,
	
};


/**
 * Represents the state of a key
 */
struct FKeyState
{
	EKeyCodes Key;
	
	EInputEvent InputState;
	
	FString DisplayName;

	bool bIsDown;

	bool bPreviousDown;

	std::vector<SDL_Event> AccumulatedEvents[IE_MAX];

	FKeyState()
		: Key(EKeyCodes::Invalid)
		, InputState(IE_MAX)
		, DisplayName("Invalid")
		, bIsDown(false)
		, bPreviousDown(false){}
	
	FKeyState(EKeyCodes InKey, FString InDisplayName)
		: Key(InKey)
		, InputState(IE_MAX)
		, DisplayName(InDisplayName)
		, bIsDown(false)
		, bPreviousDown(false)
	{
		
	}
};

/**
 * 
 */
class CInputComponent : public ISystemComponent
{
public:
	CInputComponent();
	virtual ~CInputComponent();

	virtual bool Initialize() override;

	virtual void Destroy() override;

	void HandleInputEvents(SDL_Event InEvent);

	void GetAllInputs(std::vector<FKeyState>& OutAllKeys);
	FKeyState* GetKeyState(EKeyCodes Key);

public:

	void BindAction(EInputEvent InInputEvent, EKeyCodes InKey, std::function<void()> Callback);
	
private:

	std::unordered_map<EKeyCodes, FKeyState> KeyStateMap;

	std::vector<struct FActionBinding> ActionBindings;
	//std::map<EKeys, FKeyState> KeyStateMap;
};

/**
 * Binds an action to a key
 */
struct FActionBinding
{
	EKeyCodes Key;
	EInputEvent InputEvent;
	std::function<void()> Callback = nullptr;

	FActionBinding(EInputEvent InInputEvent, EKeyCodes InKey, std::function<void()>& InCallback)
	{
		InputEvent = InInputEvent;
		Key = InKey;
		Callback = InCallback;
	}

	void Execute();

private:
	FActionBinding()
	{
		InputEvent = EInputEvent::IE_MAX;
		Key = EKeyCodes::Invalid;
		Callback = nullptr;
	}
};


/**************************************************************
 * @todo Map inputs to keys
 *
 *
 * [EKeys::Up, EKeys::W] => "MoveForward"
 * [EKeys::Down, EKeys::S] => "MoveBackwards"
 *
 *
 * struct FInputMapping
 *
 */