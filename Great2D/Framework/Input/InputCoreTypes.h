#pragma once
#include <map>
#include <memory>
#include <vector>
#include <algorithm>

#include "../Core.h"

static const FString EmptyString;

/**
 *
 */
struct FKey
{
	FKey(FString InKeyName)
	{
		KeyName = std::move(InKeyName);
	}

	bool IsModifierKey() const { return false; }
	bool IsGamepadKey() const { return false; }
	bool IsMouseButton() const { return false; }
	bool IsFloatAxis() const { return false; }
	bool IsVectorAxis() const { return false; }

	FString GetDisplayName(bool bLongDisplayName = true) const;

	friend bool operator==(const FKey& KeyA, const FKey& KeyB) { return KeyA.KeyName == KeyB.KeyName; }
	friend bool operator!=(const FKey& KeyA, const FKey& KeyB) { return KeyA.KeyName != KeyB.KeyName; }
	friend bool operator<(const FKey& KeyA, const FKey& KeyB) { return KeyA.KeyName < KeyB.KeyName; }

	friend struct EKeys;

private:
	FString KeyName;

	mutable std::shared_ptr<struct FKeyDetails> KeyDetails;
};

/**
 * 
 */
struct FKeyDetails
{
	FKeyDetails(const FKeyDetails& Copy) = default;
	FKeyDetails(const FKey InKey, const FString& InLongDisplayName, const FString& InShortDisplayName, const uint16_t InKeyFlags = 0);

	inline const FKey& GetKey() const { return Key; }
	FString GetDisplayName(const bool bLongDisplayName = true) const;

private:
	void CommonInit(const uint16_t InKeyFlags);
	
	FKey Key;
	FString LongDisplayName;
	FString ShortDisplayName;
	uint16_t KeyFlags;
};

/**
 * 
 */
struct EKeys
{
	static const FKey Up;
	static const FKey Down;
	static const FKey Left;
	static const FKey Right;

	static const FKey Invalid;

	static void Initialize();
	static void AddKey(const FKeyDetails& KeyDetails);
	static void GetAllKeys(std::vector<FKey>& OutKeys);
	
private:
	static bool bInitialized;
	static std::map<FKey, std::shared_ptr<FKeyDetails>> InputKeys;
};