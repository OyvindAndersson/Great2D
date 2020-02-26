#pragma once

class ISystemComponent
{
public:
	ISystemComponent() = default;
	
	virtual bool Initialize() = 0;

	virtual void Destroy() = 0;
};
