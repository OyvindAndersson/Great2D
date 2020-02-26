#include "InputCoreTypes.h"

#include <cassert>

#include "InputComponent.h"


const FKey EKeys::AnyKey("AnyKey");

const FKey EKeys::MouseX("MouseX");
const FKey EKeys::MouseY("MouseY");
const FKey EKeys::MouseScrollUp("MouseScrollUp");
const FKey EKeys::MouseScrollDown("MouseScrollDown");
const FKey EKeys::MouseWheelAxis("MouseWheelAxis");

const FKey EKeys::LeftMouseButton("LeftMouseButton");
const FKey EKeys::RightMouseButton("RightMouseButton");
const FKey EKeys::MiddleMouseButton("MiddleMouseButton");
const FKey EKeys::ThumbMouseButton("ThumbMouseButton");
const FKey EKeys::ThumbMouseButton2("ThumbMouseButton2");

const FKey EKeys::BackSpace("BackSpace");
const FKey EKeys::Tab("Tab");
const FKey EKeys::Enter("Enter");
const FKey EKeys::Pause("Pause");

const FKey EKeys::CapsLock("CapsLock");
const FKey EKeys::Escape("Escape");
const FKey EKeys::SpaceBar("SpaceBar");
const FKey EKeys::PageUp("PageUp");
const FKey EKeys::PageDown("PageDown");
const FKey EKeys::End("End");
const FKey EKeys::Home("Home");

const FKey EKeys::Left("Left");
const FKey EKeys::Up("Up");
const FKey EKeys::Right("Right");
const FKey EKeys::Down("Down");

const FKey EKeys::Insert("Insert");
const FKey EKeys::Delete("Delete");

const FKey EKeys::Zero("Zero");
const FKey EKeys::One("One");
const FKey EKeys::Two("Two");
const FKey EKeys::Three("Three");
const FKey EKeys::Four("Four");
const FKey EKeys::Five("Five");
const FKey EKeys::Six("Six");
const FKey EKeys::Seven("Seven");
const FKey EKeys::Eight("Eight");
const FKey EKeys::Nine("Nine");

const FKey EKeys::A("A");
const FKey EKeys::B("B");
const FKey EKeys::C("C");
const FKey EKeys::D("D");
const FKey EKeys::E("E");
const FKey EKeys::F("F");
const FKey EKeys::G("G");
const FKey EKeys::H("H");
const FKey EKeys::I("I");
const FKey EKeys::J("J");
const FKey EKeys::K("K");
const FKey EKeys::L("L");
const FKey EKeys::M("M");
const FKey EKeys::N("N");
const FKey EKeys::O("O");
const FKey EKeys::P("P");
const FKey EKeys::Q("Q");
const FKey EKeys::R("R");
const FKey EKeys::S("S");
const FKey EKeys::T("T");
const FKey EKeys::U("U");
const FKey EKeys::V("V");
const FKey EKeys::W("W");
const FKey EKeys::X("X");
const FKey EKeys::Y("Y");
const FKey EKeys::Z("Z");

const FKey EKeys::NumPadZero("NumPadZero");
const FKey EKeys::NumPadOne("NumPadOne");
const FKey EKeys::NumPadTwo("NumPadTwo");
const FKey EKeys::NumPadThree("NumPadThree");
const FKey EKeys::NumPadFour("NumPadFour");
const FKey EKeys::NumPadFive("NumPadFive");
const FKey EKeys::NumPadSix("NumPadSix");
const FKey EKeys::NumPadSeven("NumPadSeven");
const FKey EKeys::NumPadEight("NumPadEight");
const FKey EKeys::NumPadNine("NumPadNine");

const FKey EKeys::Multiply("Multiply");
const FKey EKeys::Add("Add");
const FKey EKeys::Subtract("Subtract");
const FKey EKeys::Decimal("Decimal");
const FKey EKeys::Divide("Divide");

const FKey EKeys::F1("F1");
const FKey EKeys::F2("F2");
const FKey EKeys::F3("F3");
const FKey EKeys::F4("F4");
const FKey EKeys::F5("F5");
const FKey EKeys::F6("F6");
const FKey EKeys::F7("F7");
const FKey EKeys::F8("F8");
const FKey EKeys::F9("F9");
const FKey EKeys::F10("F10");
const FKey EKeys::F11("F11");
const FKey EKeys::F12("F12");

const FKey EKeys::NumLock("NumLock");

const FKey EKeys::ScrollLock("ScrollLock");

const FKey EKeys::LeftShift("LeftShift");
const FKey EKeys::RightShift("RightShift");
const FKey EKeys::LeftControl("LeftControl");
const FKey EKeys::RightControl("RightControl");
const FKey EKeys::LeftAlt("LeftAlt");
const FKey EKeys::RightAlt("RightAlt");
const FKey EKeys::LeftCommand("LeftCommand");
const FKey EKeys::RightCommand("RightCommand");

const FKey EKeys::Semicolon("Semicolon");
const FKey EKeys::Equals("Equals");
const FKey EKeys::Comma("Comma");
const FKey EKeys::Underscore("Underscore");
const FKey EKeys::Hyphen("Hyphen");
const FKey EKeys::Period("Period");
const FKey EKeys::Slash("Slash");
const FKey EKeys::Tilde("Tilde");
const FKey EKeys::LeftBracket("LeftBracket");
const FKey EKeys::LeftParantheses("LeftParantheses");
const FKey EKeys::Backslash("Backslash");
const FKey EKeys::RightBracket("RightBracket");
const FKey EKeys::RightParantheses("RightParantheses");
const FKey EKeys::Apostrophe("Apostrophe");
const FKey EKeys::Quote("Quote");

const FKey EKeys::Asterix("Asterix");
const FKey EKeys::Ampersand("Ampersand");
const FKey EKeys::Caret("Caret");
const FKey EKeys::Dollar("Dollar");
const FKey EKeys::Exclamation("Exclamation");
const FKey EKeys::Colon("Colon");

const FKey EKeys::A_AccentGrave("A_AccentGrave");
const FKey EKeys::E_AccentGrave("E_AccentGrave");
const FKey EKeys::E_AccentAigu("E_AccentAigu");
const FKey EKeys::C_Cedille("C_Cedille");
const FKey EKeys::Section("Section");


// Setup platform specific keys
#if PLATFORM_MAC
const FKey EKeys::Platform_Delete = EKeys::BackSpace;
#else
const FKey EKeys::Platform_Delete = EKeys::Delete;
#endif

// Ensure that the Gamepad_ names match those in GenericApplication.cpp
const FKey EKeys::Gamepad_LeftX("Gamepad_LeftX");
const FKey EKeys::Gamepad_LeftY("Gamepad_LeftY");
const FKey EKeys::Gamepad_RightX("Gamepad_RightX");
const FKey EKeys::Gamepad_RightY("Gamepad_RightY");
const FKey EKeys::Gamepad_LeftTriggerAxis("Gamepad_LeftTriggerAxis");
const FKey EKeys::Gamepad_RightTriggerAxis("Gamepad_RightTriggerAxis");

const FKey EKeys::Gamepad_LeftThumbstick("Gamepad_LeftThumbstick");
const FKey EKeys::Gamepad_RightThumbstick("Gamepad_RightThumbstick");
const FKey EKeys::Gamepad_Special_Left("Gamepad_Special_Left");
const FKey EKeys::Gamepad_Special_Left_X("Gamepad_Special_Left_X");
const FKey EKeys::Gamepad_Special_Left_Y("Gamepad_Special_Left_Y");
const FKey EKeys::Gamepad_Special_Right("Gamepad_Special_Right");
const FKey EKeys::Gamepad_FaceButton_Bottom("Gamepad_FaceButton_Bottom");
const FKey EKeys::Gamepad_FaceButton_Right("Gamepad_FaceButton_Right");
const FKey EKeys::Gamepad_FaceButton_Left("Gamepad_FaceButton_Left");
const FKey EKeys::Gamepad_FaceButton_Top("Gamepad_FaceButton_Top");
const FKey EKeys::Gamepad_LeftShoulder("Gamepad_LeftShoulder");
const FKey EKeys::Gamepad_RightShoulder("Gamepad_RightShoulder");
const FKey EKeys::Gamepad_LeftTrigger("Gamepad_LeftTrigger");
const FKey EKeys::Gamepad_RightTrigger("Gamepad_RightTrigger");
const FKey EKeys::Gamepad_DPad_Up("Gamepad_DPad_Up");
const FKey EKeys::Gamepad_DPad_Down("Gamepad_DPad_Down");
const FKey EKeys::Gamepad_DPad_Right("Gamepad_DPad_Right");
const FKey EKeys::Gamepad_DPad_Left("Gamepad_DPad_Left");

// Virtual key codes used for input axis button press/release emulation
const FKey EKeys::Gamepad_LeftStick_Up("Gamepad_LeftStick_Up");
const FKey EKeys::Gamepad_LeftStick_Down("Gamepad_LeftStick_Down");
const FKey EKeys::Gamepad_LeftStick_Right("Gamepad_LeftStick_Right");
const FKey EKeys::Gamepad_LeftStick_Left("Gamepad_LeftStick_Left");

const FKey EKeys::Gamepad_RightStick_Up("Gamepad_RightStick_Up");
const FKey EKeys::Gamepad_RightStick_Down("Gamepad_RightStick_Down");
const FKey EKeys::Gamepad_RightStick_Right("Gamepad_RightStick_Right");
const FKey EKeys::Gamepad_RightStick_Left("Gamepad_RightStick_Left");

// const FKey EKeys::Vector axes (FVector("Vector axes (FVector"); not float)
const FKey EKeys::Tilt("Tilt");
const FKey EKeys::RotationRate("RotationRate");
const FKey EKeys::Gravity("Gravity");
const FKey EKeys::Acceleration("Acceleration");

// PS4-specific
const FKey EKeys::PS4_Special("PS4_Special");


// Xbox One global speech commands
const FKey EKeys::Global_Menu("Global_Menu");
const FKey EKeys::Global_View("Global_View");
const FKey EKeys::Global_Pause("Global_Pause");
const FKey EKeys::Global_Play("Global_Play");
const FKey EKeys::Global_Back("Global_Back");


const FKey EKeys::Invalid("NONE");

bool EKeys::bInitialized = false;

//std::map<FKey, std::shared_ptr<FKeyDetails> > EKeys::InputKeys;

FKeyDetails::FKeyDetails(const FKey InKey, const std::string& InLongDisplayName, const uint16_t InKeyFlags, const std::string& InShortDisplayName)
	: Key(InKey)
	, LongDisplayName(InLongDisplayName)
	, ShortDisplayName(InShortDisplayName)
{
	CommonInit(InKeyFlags);
}

FKeyDetails::FKeyDetails(const FKey InKey, const std::string& InLongDisplayName, const std::string& InShortDisplayName, const uint16_t InKeyFlags)
	: Key(InKey)
	, LongDisplayName(InLongDisplayName)
	, ShortDisplayName(InShortDisplayName)
{
	CommonInit(InKeyFlags);
}

std::string FKeyDetails::GetDisplayName(const bool bLongDisplayName) const
{
	return std::string();
}

void FKeyDetails::CommonInit(const uint16_t InKeyFlags)
{
	bIsModifierKey = ((InKeyFlags & EKeyFlags::ModifierKey) != 0);
	bIsGamepadKey = ((InKeyFlags & EKeyFlags::GamepadKey) != 0);
	bIsTouch = ((InKeyFlags & EKeyFlags::Touch) != 0);
	bIsMouseButton = ((InKeyFlags & EKeyFlags::MouseButton) != 0);
	bShouldUpdateAxisWithoutSamples = ((InKeyFlags & EKeyFlags::UpdateAxisWithoutSamples) != 0);
	bIsBindableToActions = ((~InKeyFlags & EKeyFlags::NotActionBindableKey) != 0) && ((~InKeyFlags & EKeyFlags::Deprecated) != 0);
	bIsDeprecated = ((InKeyFlags & EKeyFlags::Deprecated) != 0);

	if ((InKeyFlags & EKeyFlags::FloatAxis) != 0)
	{
		assert((InKeyFlags & EKeyFlags::VectorAxis) == 0);
		AxisType = EInputAxisType::Float;
	}
	else if ((InKeyFlags & EKeyFlags::VectorAxis) != 0)
	{
		AxisType = EInputAxisType::Vector;
	}
	else
	{
		AxisType = EInputAxisType::None;
	}
}


void EKeys::Initialize()
{
	if (bInitialized) return;
	bInitialized = true;

	AddKey(FKeyDetails(EKeys::AnyKey, "Any Key"));

	AddKey(FKeyDetails(EKeys::MouseX,  "Mouse X", FKeyDetails::FloatAxis | FKeyDetails::MouseButton | FKeyDetails::UpdateAxisWithoutSamples));
	AddKey(FKeyDetails(EKeys::MouseY, "Mouse Y", FKeyDetails::FloatAxis | FKeyDetails::MouseButton | FKeyDetails::UpdateAxisWithoutSamples));
	AddKey(FKeyDetails(EKeys::MouseWheelAxis,  "Mouse Wheel Axis", FKeyDetails::FloatAxis | FKeyDetails::MouseButton | FKeyDetails::UpdateAxisWithoutSamples));
	AddKey(FKeyDetails(EKeys::MouseScrollUp,  "Mouse Wheel Up", FKeyDetails::MouseButton));
	AddKey(FKeyDetails(EKeys::MouseScrollDown,  "Mouse Wheel Down", FKeyDetails::MouseButton));

	AddKey(FKeyDetails(EKeys::LeftMouseButton, "Left Mouse Button", FKeyDetails::MouseButton));
	AddKey(FKeyDetails(EKeys::RightMouseButton, "Right Mouse Button", FKeyDetails::MouseButton));
	AddKey(FKeyDetails(EKeys::MiddleMouseButton,  "Middle Mouse Button", FKeyDetails::MouseButton));
	AddKey(FKeyDetails(EKeys::ThumbMouseButton, "Thumb Mouse Button", FKeyDetails::MouseButton));
	AddKey(FKeyDetails(EKeys::ThumbMouseButton2, "Thumb Mouse Button 2", FKeyDetails::MouseButton));

	AddKey(FKeyDetails(EKeys::Tab,  "Tab"));
	AddKey(FKeyDetails(EKeys::Enter, "Enter"));
	AddKey(FKeyDetails(EKeys::Pause, "Pause"));

	AddKey(FKeyDetails(EKeys::CapsLock, "Caps Lock",  "Caps"));
	AddKey(FKeyDetails(EKeys::Escape, "Escape","Esc"));
	AddKey(FKeyDetails(EKeys::SpaceBar, "Space Bar", "Space"));
	AddKey(FKeyDetails(EKeys::PageUp, "Page Up",  "PgUp"));
	AddKey(FKeyDetails(EKeys::PageDown,  "Page Down",  "PgDn"));
	AddKey(FKeyDetails(EKeys::End,  "End"));
	AddKey(FKeyDetails(EKeys::Home,  "Home"));

	AddKey(FKeyDetails(EKeys::Left,  "Left"));
	AddKey(FKeyDetails(EKeys::Up, "Up"));
	AddKey(FKeyDetails(EKeys::Right,  "Right"));
	AddKey(FKeyDetails(EKeys::Down,  "Down"));

	AddKey(FKeyDetails(EKeys::Insert, "Insert", "Ins"));

#if PLATFORM_MAC
	AddKey(FKeyDetails(EKeys::BackSpace, "Delete", "Del"));
	AddKey(FKeyDetails(EKeys::Delete, "Fn+Delete"));
#else
	AddKey(FKeyDetails(EKeys::BackSpace,  "Backspace"));
	AddKey(FKeyDetails(EKeys::Delete, "Delete", "Del"));
#endif

	AddKey(FKeyDetails(EKeys::Zero, "0"));
	AddKey(FKeyDetails(EKeys::One, "1"));
	AddKey(FKeyDetails(EKeys::Two, "2"));
	AddKey(FKeyDetails(EKeys::Three, "3"));
	AddKey(FKeyDetails(EKeys::Four, "4"));
	AddKey(FKeyDetails(EKeys::Five, "5"));
	AddKey(FKeyDetails(EKeys::Six, "6"));
	AddKey(FKeyDetails(EKeys::Seven, "7"));
	AddKey(FKeyDetails(EKeys::Eight, "8"));
	AddKey(FKeyDetails(EKeys::Nine, "9"));

	AddKey(FKeyDetails(EKeys::A, "A"));
	AddKey(FKeyDetails(EKeys::B, "B"));
	AddKey(FKeyDetails(EKeys::C, "C"));
	AddKey(FKeyDetails(EKeys::D, "D"));
	AddKey(FKeyDetails(EKeys::E, "E"));
	AddKey(FKeyDetails(EKeys::F, "F"));
	AddKey(FKeyDetails(EKeys::G, "G"));
	AddKey(FKeyDetails(EKeys::H, "H"));
	AddKey(FKeyDetails(EKeys::I, "I"));
	AddKey(FKeyDetails(EKeys::J, "J"));
	AddKey(FKeyDetails(EKeys::K, "K"));
	AddKey(FKeyDetails(EKeys::L, "L"));
	AddKey(FKeyDetails(EKeys::M, "M"));
	AddKey(FKeyDetails(EKeys::N, "N"));
	AddKey(FKeyDetails(EKeys::O, "O"));
	AddKey(FKeyDetails(EKeys::P, "P"));
	AddKey(FKeyDetails(EKeys::Q, "Q"));
	AddKey(FKeyDetails(EKeys::R, "R"));
	AddKey(FKeyDetails(EKeys::S, "S"));
	AddKey(FKeyDetails(EKeys::T, "T"));
	AddKey(FKeyDetails(EKeys::U, "U"));
	AddKey(FKeyDetails(EKeys::V, "V"));
	AddKey(FKeyDetails(EKeys::W, "W"));
	AddKey(FKeyDetails(EKeys::X, "X"));
	AddKey(FKeyDetails(EKeys::Y, "Y"));
	AddKey(FKeyDetails(EKeys::Z, "Z"));

	AddKey(FKeyDetails(EKeys::NumPadZero, "Num 0"));
	AddKey(FKeyDetails(EKeys::NumPadOne, "Num 1"));
	AddKey(FKeyDetails(EKeys::NumPadTwo, "Num 2"));
	AddKey(FKeyDetails(EKeys::NumPadThree, "Num 3"));
	AddKey(FKeyDetails(EKeys::NumPadFour, "Num 4"));
	AddKey(FKeyDetails(EKeys::NumPadFive, "Num 5"));
	AddKey(FKeyDetails(EKeys::NumPadSix, "Num 6"));
	AddKey(FKeyDetails(EKeys::NumPadSeven, "Num 7"));
	AddKey(FKeyDetails(EKeys::NumPadEight, "Num 8"));
	AddKey(FKeyDetails(EKeys::NumPadNine, "Num 9"));

	AddKey(FKeyDetails(EKeys::Multiply, "Num *"));
	AddKey(FKeyDetails(EKeys::Add, "Num +"));
	AddKey(FKeyDetails(EKeys::Subtract, "Num -"));
	AddKey(FKeyDetails(EKeys::Decimal, "Num ."));
	AddKey(FKeyDetails(EKeys::Divide, "Num /"));

	AddKey(FKeyDetails(EKeys::F1, "F1"));
	AddKey(FKeyDetails(EKeys::F2, "F2"));
	AddKey(FKeyDetails(EKeys::F3, "F3"));
	AddKey(FKeyDetails(EKeys::F4, "F4"));
	AddKey(FKeyDetails(EKeys::F5, "F5"));
	AddKey(FKeyDetails(EKeys::F6, "F6"));
	AddKey(FKeyDetails(EKeys::F7, "F7"));
	AddKey(FKeyDetails(EKeys::F8, "F8"));
	AddKey(FKeyDetails(EKeys::F9, "F9"));
	AddKey(FKeyDetails(EKeys::F10, "F10"));
	AddKey(FKeyDetails(EKeys::F11, "F11"));
	AddKey(FKeyDetails(EKeys::F12, "F12"));

	AddKey(FKeyDetails(EKeys::NumLock, "Num Lock"));
	AddKey(FKeyDetails(EKeys::ScrollLock, "Scroll Lock"));

	AddKey(FKeyDetails(EKeys::LeftShift, "Left Shift", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::RightShift, "Right Shift", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::LeftControl, "Left Ctrl", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::RightControl, "Right Ctrl", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::LeftAlt, "Left Alt", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::RightAlt, "Right Alt", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::LeftCommand, "Left Cmd", FKeyDetails::ModifierKey));
	AddKey(FKeyDetails(EKeys::RightCommand, "Right Cmd", FKeyDetails::ModifierKey));

	AddKey(FKeyDetails(EKeys::Semicolon, "Semicolon", ";"));
	AddKey(FKeyDetails(EKeys::Equals, "Equals", "="));
	AddKey(FKeyDetails(EKeys::Comma, "Comma", ","));
	AddKey(FKeyDetails(EKeys::Hyphen, "Hyphen", "-"));
	AddKey(FKeyDetails(EKeys::Underscore, "Underscore", "_"));
	AddKey(FKeyDetails(EKeys::Period, "Period", "."));
	AddKey(FKeyDetails(EKeys::Slash, "Slash", "/"));
	AddKey(FKeyDetails(EKeys::Tilde, "`")); // Yes this is not actually a tilde, it is a long, sad, and old story
	AddKey(FKeyDetails(EKeys::LeftBracket, "Left Bracket", "["));
	AddKey(FKeyDetails(EKeys::Backslash, "Backslash", "\\"));
	AddKey(FKeyDetails(EKeys::RightBracket, "Right Bracket", "]"));
	AddKey(FKeyDetails(EKeys::Apostrophe, "Apostrophe", "'"));
	AddKey(FKeyDetails(EKeys::Quote, "Quote", "\""));

	AddKey(FKeyDetails(EKeys::LeftParantheses, "Left Parantheses", "("));
	AddKey(FKeyDetails(EKeys::RightParantheses, "Right Parantheses", ")"));
	AddKey(FKeyDetails(EKeys::Ampersand, "Ampersand", "&"));
	AddKey(FKeyDetails(EKeys::Asterix, "Asterisk", "*"));
	AddKey(FKeyDetails(EKeys::Caret, "Caret", "^"));
	AddKey(FKeyDetails(EKeys::Dollar, "Dollar", "$"));
	AddKey(FKeyDetails(EKeys::Exclamation, "Exclamation", "!"));
	AddKey(FKeyDetails(EKeys::Colon, "Colon", ":"));

	//AddKey(FKeyDetails(EKeys::A_AccentGrave, FText::FromString(FString::Chr(224))));
	//AddKey(FKeyDetails(EKeys::E_AccentGrave, FText::FromString(FString::Chr(232))));
	//AddKey(FKeyDetails(EKeys::E_AccentAigu, FText::FromString(FString::Chr(233))));
	//AddKey(FKeyDetails(EKeys::C_Cedille, FText::FromString(FString::Chr(231))));
	//AddKey(FKeyDetails(EKeys::Section, FText::FromString(FString::Chr(167))));


	// Setup Gamepad keys
	AddKey(FKeyDetails(EKeys::Gamepad_LeftX, "Gamepad Left Thumbstick X-Axis", FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
	AddKey(FKeyDetails(EKeys::Gamepad_LeftY, "Gamepad Left Thumbstick Y-Axis", FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
	AddKey(FKeyDetails(EKeys::Gamepad_RightX, "Gamepad Right Thumbstick X-Axis", FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
	AddKey(FKeyDetails(EKeys::Gamepad_RightY, "Gamepad Right Thumbstick Y-Axis", FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));

	AddKey(FKeyDetails(EKeys::Gamepad_DPad_Up, "Gamepad D-pad Up", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_DPad_Down, "Gamepad D-pad Down", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_DPad_Right, "Gamepad D-pad Right", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_DPad_Left, "Gamepad D-pad Left", FKeyDetails::GamepadKey));

	// Virtual key codes used for input axis button press/release emulation
	AddKey(FKeyDetails(EKeys::Gamepad_LeftStick_Up, "Gamepad Left Thumbstick Up", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_LeftStick_Down, "Gamepad Left Thumbstick Down", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_LeftStick_Right, "Gamepad Left Thumbstick Right", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_LeftStick_Left, "Gamepad Left Thumbstick Left", FKeyDetails::GamepadKey));

	AddKey(FKeyDetails(EKeys::Gamepad_RightStick_Up, "Gamepad Right Thumbstick Up", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_RightStick_Down, "Gamepad Right Thumbstick Down", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_RightStick_Right, "Gamepad Right Thumbstick Right", FKeyDetails::GamepadKey));
	AddKey(FKeyDetails(EKeys::Gamepad_RightStick_Left, "Gamepad Right Thumbstick Left", FKeyDetails::GamepadKey));

	//AddKey(FKeyDetails(EKeys::Gamepad_Special_Left, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_Special_Right, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_FaceButton_Bottom, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_FaceButton_Right, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_FaceButton_Left, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_FaceButton_Top, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));

	//AddKey(FKeyDetails(EKeys::Gamepad_LeftTriggerAxis, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
	//AddKey(FKeyDetails(EKeys::Gamepad_RightTriggerAxis, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));

	//AddKey(FKeyDetails(EKeys::Gamepad_LeftShoulder, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_RightShoulder, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_LeftTrigger, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_RightTrigger, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));

	//AddKey(FKeyDetails(EKeys::Gamepad_LeftThumbstick, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));
	//AddKey(FKeyDetails(EKeys::Gamepad_RightThumbstick, EKeys::GetGamepadDisplayName, FKeyDetails::GamepadKey));

	AddKey(FKeyDetails(EKeys::Tilt, "Tilt", FKeyDetails::VectorAxis, "Motion"));
	AddKey(FKeyDetails(EKeys::RotationRate, "Rotation Rate", FKeyDetails::VectorAxis, "Motion"));
	AddKey(FKeyDetails(EKeys::Gravity, "Gravity", FKeyDetails::VectorAxis, "Motion"));
	AddKey(FKeyDetails(EKeys::Acceleration, "Acceleration", FKeyDetails::VectorAxis, "Motion"));


	// PS4-specific
	AddKey(FKeyDetails(EKeys::PS4_Special, "PS4_Special", FKeyDetails::NotBlueprintBindableKey | FKeyDetails::NotActionBindableKey, "PS4"));
	AddKey(FKeyDetails(EKeys::Gamepad_Special_Left_X, "PS4 Touchpad Button X Axis", FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PS4"));
	AddKey(FKeyDetails(EKeys::Gamepad_Special_Left_Y, "PS4 Touchpad Button Y Axis", FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PS4"));


	AddKey(FKeyDetails(EKeys::Global_Menu, "Global Menu", FKeyDetails::GamepadKey, "XBoxOne"));
	AddKey(FKeyDetails(EKeys::Global_View, "Global View", FKeyDetails::GamepadKey, "XBoxOne"));
	AddKey(FKeyDetails(EKeys::Global_Pause, "Global Pause", FKeyDetails::GamepadKey, "XBoxOne"));
	AddKey(FKeyDetails(EKeys::Global_Play, "Global Play", FKeyDetails::GamepadKey, "XBoxOne"));
	AddKey(FKeyDetails(EKeys::Global_Back, LOCTEXT("Global_Back", "Global Back"), FKeyDetails::GamepadKey, "XBoxOne"));

	// Initialize the input key manager.  This will cause any additional OEM keys to get added
	FInputKeyManager::Get();
}

void EKeys::AddKey(const FKeyDetails& KeyDetails)
{
	const FKey& Key = KeyDetails.GetKey();
	Key.KeyDetails = std::make_shared<FKeyDetails*>(new FKeyDetails(KeyDetails));
	InputKeys[Key] = Key.KeyDetails;
}


void EKeys::GetAllKeys(std::vector<FKey>& OutKeys)
{
	for(auto v : InputKeys)
	{
		OutKeys.push_back(v.first);
	}
}