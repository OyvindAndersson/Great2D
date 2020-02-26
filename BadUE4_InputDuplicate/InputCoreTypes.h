#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <memory>

/**
 * Represents a single key in an event
 */
struct FKey
{
	FKey(std::string InKeyName)
	{
		KeyName = std::move(InKeyName);
	}

	bool IsModifierKey() const;
	bool IsGamepadKey() const;
	bool IsMouseButton() const;
	bool IsFloatAxis() const;
	bool IsVectorAxis() const;
	
	std::string GetDisplayName(bool bLongDisplayName = true) const;
	std::string ToString() const;

	friend bool operator==(const FKey& KeyA, const FKey& KeyB) { return KeyA.KeyName == KeyB.KeyName; }
	friend bool operator!=(const FKey& KeyA, const FKey& KeyB) { return KeyA.KeyName != KeyB.KeyName; }

	friend struct EKeys;

private:

	std::string KeyName;

	mutable std::shared_ptr<struct FKeyDetails> KeyDetails;

	void ConditionalLookupKeyDetails() const;
	void ResetKey();
};

/**
 * 
 */
struct FKeyDetails
{
	enum EKeyFlags
	{
		GamepadKey = 1 << 0,
		Touch = 1 << 1,
		MouseButton = 1 << 2,
		ModifierKey = 1 << 3,
		NotBlueprintBindableKey = 1 << 4,
		FloatAxis = 1 << 5,
		VectorAxis = 1 << 6,
		UpdateAxisWithoutSamples = 1 << 7,
		NotActionBindableKey = 1 << 8,
		Deprecated = 1 << 9,

		NoFlags = 0,
	};

	FKeyDetails(const FKeyDetails& Copy)
	: Key(Copy.Key)
	, bIsModifierKey(Copy.bIsModifierKey)
	, bIsGamepadKey(Copy.bIsGamepadKey)
	, bIsTouch(Copy.bIsTouch)
	, bIsMouseButton(Copy.bIsMouseButton)
	, bShouldUpdateAxisWithoutSamples(Copy.bShouldUpdateAxisWithoutSamples)
	, bIsBindableToActions(Copy.bIsBindableToActions)
	, AxisType(Copy.AxisType)
	, LongDisplayName(Copy.LongDisplayName)
	, ShortDisplayName(Copy.ShortDisplayName)
	{}
	FKeyDetails(const FKey InKey, const std::string& InLongDisplayName, const uint16_t InKeyFlags = 0, const std::string& InShortDisplayName = std::string());
	FKeyDetails(const FKey InKey, const std::string& InLongDisplayName, const std::string& InShortDisplayName, const uint16_t InKeyFlags = 0);

	inline bool IsModifierKey() const { return bIsModifierKey != 0; }
	inline bool IsGamepadKey() const { return bIsGamepadKey != 0; }
	inline bool IsTouch() const { return bIsTouch != 0; }
	inline bool IsMouseButton() const { return bIsMouseButton != 0; }
	inline bool IsFloatAxis() const { return AxisType == EInputAxisType::Float; }
	inline bool IsVectorAxis() const { return AxisType == EInputAxisType::Vector; }
	inline bool ShouldUpdateAxisWithoutSamples() const { return bShouldUpdateAxisWithoutSamples != 0; }
	inline bool IsBindableToActions() const { return bIsBindableToActions != 0; }
	inline bool IsDeprecated() const { return bIsDeprecated != 0; }
	std::string GetDisplayName(const bool bLongDisplayName = true) const;
	inline const FKey& GetKey() const { return Key; }

private:

	void CommonInit(const uint16_t InKeyFlags);

	enum class EInputAxisType : uint8_t
	{
		None,
		Float,
		Vector
	};

	FKey  Key;

	uint8_t bIsModifierKey : 1;
	uint8_t bIsGamepadKey : 1;
	uint8_t bIsTouch : 1;
	uint8_t bIsMouseButton : 1;
	uint8_t bShouldUpdateAxisWithoutSamples : 1;
	uint8_t bIsBindableToActions : 1;
	uint8_t bIsDeprecated : 1;
	EInputAxisType AxisType;

	std::string LongDisplayName;
	std::string ShortDisplayName;
};

/**
 * 
 */
struct EKeys
{
	static const FKey AnyKey;

	static const FKey MouseX;
	static const FKey MouseY;
	static const FKey MouseScrollUp;
	static const FKey MouseScrollDown;
	static const FKey MouseWheelAxis;

	static const FKey LeftMouseButton;
	static const FKey RightMouseButton;
	static const FKey MiddleMouseButton;
	static const FKey ThumbMouseButton;
	static const FKey ThumbMouseButton2;

	static const FKey BackSpace;
	static const FKey Tab;
	static const FKey Enter;
	static const FKey Pause;

	static const FKey CapsLock;
	static const FKey Escape;
	static const FKey SpaceBar;
	static const FKey PageUp;
	static const FKey PageDown;
	static const FKey End;
	static const FKey Home;

	static const FKey Left;
	static const FKey Up;
	static const FKey Right;
	static const FKey Down;

	static const FKey Insert;
	static const FKey Delete;

	static const FKey Zero;
	static const FKey One;
	static const FKey Two;
	static const FKey Three;
	static const FKey Four;
	static const FKey Five;
	static const FKey Six;
	static const FKey Seven;
	static const FKey Eight;
	static const FKey Nine;

	static const FKey A;
	static const FKey B;
	static const FKey C;
	static const FKey D;
	static const FKey E;
	static const FKey F;
	static const FKey G;
	static const FKey H;
	static const FKey I;
	static const FKey J;
	static const FKey K;
	static const FKey L;
	static const FKey M;
	static const FKey N;
	static const FKey O;
	static const FKey P;
	static const FKey Q;
	static const FKey R;
	static const FKey S;
	static const FKey T;
	static const FKey U;
	static const FKey V;
	static const FKey W;
	static const FKey X;
	static const FKey Y;
	static const FKey Z;

	static const FKey NumPadZero;
	static const FKey NumPadOne;
	static const FKey NumPadTwo;
	static const FKey NumPadThree;
	static const FKey NumPadFour;
	static const FKey NumPadFive;
	static const FKey NumPadSix;
	static const FKey NumPadSeven;
	static const FKey NumPadEight;
	static const FKey NumPadNine;

	static const FKey Multiply;
	static const FKey Add;
	static const FKey Subtract;
	static const FKey Decimal;
	static const FKey Divide;

	static const FKey F1;
	static const FKey F2;
	static const FKey F3;
	static const FKey F4;
	static const FKey F5;
	static const FKey F6;
	static const FKey F7;
	static const FKey F8;
	static const FKey F9;
	static const FKey F10;
	static const FKey F11;
	static const FKey F12;

	static const FKey NumLock;

	static const FKey ScrollLock;

	static const FKey LeftShift;
	static const FKey RightShift;
	static const FKey LeftControl;
	static const FKey RightControl;
	static const FKey LeftAlt;
	static const FKey RightAlt;
	static const FKey LeftCommand;
	static const FKey RightCommand;

	static const FKey Semicolon;
	static const FKey Equals;
	static const FKey Comma;
	static const FKey Underscore;
	static const FKey Hyphen;
	static const FKey Period;
	static const FKey Slash;
	static const FKey Tilde;
	static const FKey LeftBracket;
	static const FKey Backslash;
	static const FKey RightBracket;
	static const FKey Apostrophe;

	static const FKey Ampersand;
	static const FKey Asterix;
	static const FKey Caret;
	static const FKey Colon;
	static const FKey Dollar;
	static const FKey Exclamation;
	static const FKey LeftParantheses;
	static const FKey RightParantheses;
	static const FKey Quote;

	static const FKey A_AccentGrave;
	static const FKey E_AccentGrave;
	static const FKey E_AccentAigu;
	static const FKey C_Cedille;
	static const FKey Section;

	// Platform Keys
	// These keys platform specific versions of keys that go by different names.
	// The delete key is a good example, on Windows Delete is the virtual key for Delete.
	// On Macs, the Delete key is the virtual key for BackSpace.
	static const FKey Platform_Delete;

	// Gamepad Keys
	static const FKey Gamepad_LeftX;
	static const FKey Gamepad_LeftY;
	static const FKey Gamepad_RightX;
	static const FKey Gamepad_RightY;
	static const FKey Gamepad_LeftTriggerAxis;
	static const FKey Gamepad_RightTriggerAxis;

	static const FKey Gamepad_LeftThumbstick;
	static const FKey Gamepad_RightThumbstick;
	static const FKey Gamepad_Special_Left;
	static const FKey Gamepad_Special_Left_X;
	static const FKey Gamepad_Special_Left_Y;
	static const FKey Gamepad_Special_Right;
	static const FKey Gamepad_FaceButton_Bottom;
	static const FKey Gamepad_FaceButton_Right;
	static const FKey Gamepad_FaceButton_Left;
	static const FKey Gamepad_FaceButton_Top;
	static const FKey Gamepad_LeftShoulder;
	static const FKey Gamepad_RightShoulder;
	static const FKey Gamepad_LeftTrigger;
	static const FKey Gamepad_RightTrigger;
	static const FKey Gamepad_DPad_Up;
	static const FKey Gamepad_DPad_Down;
	static const FKey Gamepad_DPad_Right;
	static const FKey Gamepad_DPad_Left;

	// Virtual key codes used for input axis button press/release emulation
	static const FKey Gamepad_LeftStick_Up;
	static const FKey Gamepad_LeftStick_Down;
	static const FKey Gamepad_LeftStick_Right;
	static const FKey Gamepad_LeftStick_Left;

	static const FKey Gamepad_RightStick_Up;
	static const FKey Gamepad_RightStick_Down;
	static const FKey Gamepad_RightStick_Right;
	static const FKey Gamepad_RightStick_Left;

	// static const FKey Vector axes (FVector; not float)
	static const FKey Tilt;
	static const FKey RotationRate;
	static const FKey Gravity;
	static const FKey Acceleration;

	// PS4-specific
	static const FKey PS4_Special;

	// Xbox One global speech commands
	static const FKey Global_Menu;
	static const FKey Global_View;
	static const FKey Global_Pause;
	static const FKey Global_Play;
	static const FKey Global_Back;

	// Virtual buttons that use other buttons depending on the platform
	static const FKey Virtual_Accept;
	static const FKey Virtual_Back;

	static const FKey Invalid;

	static void Initialize();
	static void AddKey(const FKeyDetails& KeyDetails);
	static void GetAllKeys(std::vector<FKey>& OutKeys);
	static std::shared_ptr<FKeyDetails> GetKeyDetails(const FKey Key);


private:

	static std::map<FKey, std::shared_ptr<FKeyDetails> > InputKeys;
	static bool bInitialized;

};