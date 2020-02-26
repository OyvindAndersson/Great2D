#pragma once

#include <map>
#include <vector>


#include "../Application/ISystemComponent.h"
#include "InputCoreTypes.h"

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
 * Represents the state of a key
 */
struct FKeyState
{
	uint8_t bConsumed : 1;

	uint8_t bDown : 1;

	uint8_t bDownPrevious : 1;

	std::vector<uint32_t> EventAccumulator[EInputEvent::IE_MAX];

	FKeyState()
		: bConsumed(false)
		, bDown(false)
		, bDownPrevious(false)
	{
		
	}
};

struct FInputKeyManager
{
public:
	static FInputKeyManager& Get();

	void GetCodesFromKey(const FKey Key, const uint32_t*& KeyCode, const uint32_t*& CharCode) const;

	FKey GetKeyFromCodes(const uint32_t KeyCode, const uint32_t CharCode) const;

	void InitKeyMappings();

private:
	FInputKeyManager()
	{
		InitKeyMappings();
	}

	static std::shared_ptr<FInputKeyManager> Instance;
	std::map<uint32_t, FKey> KeyMapVirtualToEnum;
	std::map<uint32_t, FKey> KeyMapCharToEnum;
};

class CInputComponent : public ISystemComponent
{
public:
	CInputComponent();

	virtual bool Initialize() override;

	virtual void Destroy() override;

private:

	//std::map<FKey, FKeyState> KeyStateMap;
};

