#pragma once
#include "Command/MenuCommand.h"

class Menu;

class RulesCommand : public MenuCommand
{
public:
	using MenuCommand::MenuCommand;
	//RulesCommand(Menu&);
	virtual void axecute() override;
private:
};
