#pragma once
#include "Command/CommandInterface.h"

class Menu;

class RulesCommand : public CommandInterface
{
public:
	using CommandInterface::CommandInterface;
	//RulesCommand(Menu&);
	virtual void axecute() override;
private:
};
