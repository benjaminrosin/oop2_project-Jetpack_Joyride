#pragma once
#include "Command/MenuCommand.h"

class Menu;

class HighScoreCommand : public MenuCommand
{
public:
	using MenuCommand::MenuCommand;
	virtual void axecute() override;

};
