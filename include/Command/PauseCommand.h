#pragma once
#include "Command/MenuCommandInterface.h"


class PauseCommand : public MenuCommandInterface
{
public:
	PauseCommand();
	virtual void axecute() override;
private:
	
};
