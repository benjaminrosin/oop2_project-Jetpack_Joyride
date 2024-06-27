#pragma once
#include "Command/MenuCommand.h"

class Menu;

class HighScoreCommand : public MenuCommand
{
public:
	using MenuCommand::MenuCommand;
	//HighScoreCommand(Menu&);
	virtual void axecute() override;
private:

};
