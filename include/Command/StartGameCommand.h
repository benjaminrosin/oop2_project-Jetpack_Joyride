#pragma once
#include "Command/MenuCommand.h"

class Menu;

class StartGameCommand : public MenuCommand
{
public:
	using MenuCommand::MenuCommand;
	//StartGameCommand(Menu&);
	virtual void axecute() override;
private:

};
