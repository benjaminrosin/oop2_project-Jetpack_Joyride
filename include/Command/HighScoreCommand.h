#pragma once
#include "Command/CommandInterface.h"

class Menu;

class HighScoreCommand : public CommandInterface
{
public:
	using CommandInterface::CommandInterface;
	//HighScoreCommand(Menu&);
	virtual void axecute() override;
private:

};
