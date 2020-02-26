#include "InputCoreTypes.h"

// Init key names
const FKey EKeys::Left("Left");
const FKey EKeys::Up("Up");
const FKey EKeys::Right("Right");
const FKey EKeys::Down("Down");
const FKey EKeys::Invalid("NONE");

// First init
bool EKeys::bInitialized = false;

std::map<FKey, std::shared_ptr<FKeyDetails> > EKeys::InputKeys;

/**
 * FKeyDetails implementation
 */
FKeyDetails::FKeyDetails(const FKey InKey, const FString& InLongDisplayName, const FString& InShortDisplayName, const uint16_t InKeyFlags)
	: Key(InKey)
	, LongDisplayName(InLongDisplayName)
	, ShortDisplayName(InShortDisplayName)
	, KeyFlags(InKeyFlags)
{
	CommonInit(InKeyFlags);
}

/**
 * 
 */
FString FKeyDetails::GetDisplayName(const bool bLongDisplayName) const
{
	return bLongDisplayName ? LongDisplayName : ShortDisplayName;
}

/**
 * 
 */
void FKeyDetails::CommonInit(const uint16_t InKeyFlags)
{
	/*
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
	*/
}

/**
 * 
 */
void EKeys::Initialize()
{
	if (bInitialized) return;
	bInitialized = true;

	AddKey(FKeyDetails(EKeys::Up, "Up Arrow", "Up"));
	AddKey(FKeyDetails(EKeys::Down, "Down Arrow", "Down"));
	AddKey(FKeyDetails(EKeys::Left, "Left Arrow", "Left"));
	AddKey(FKeyDetails(EKeys::Right, "Right Arrow", "Right"));

	AddKey(FKeyDetails(EKeys::Invalid, "Invalid", "Invalid"));
}

/**
 * 
 */
void EKeys::AddKey(const FKeyDetails& KeyDetails)
{
	const FKey& Key = KeyDetails.GetKey();

	Key.KeyDetails = std::shared_ptr<FKeyDetails>(new FKeyDetails(KeyDetails));
	//Key.KeyDetails = std::make_shared<FKeyDetails>(KeyDetails);

	InputKeys[Key] = Key.KeyDetails;
}

/**
 * 
 */
void EKeys::GetAllKeys(std::vector<FKey>& OutKeys)
{
	for (auto v : InputKeys)
	{
		OutKeys.push_back(v.first);
	}
}

/**
 *
 */
FString FKey::GetDisplayName(bool bLongDisplayName) const
{
	if (bLongDisplayName)
	{
		if (KeyDetails != nullptr)
		{
			return KeyDetails->GetDisplayName(bLongDisplayName);
		}
		else
		{
			return EmptyString;
		}
	}
	else
	{
		return EmptyString;
	}
}