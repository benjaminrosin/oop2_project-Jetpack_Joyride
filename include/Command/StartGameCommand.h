#pragma once
#include "Command/CommandInterface.h"

class Menu;

class StartGameCommand : public CommandInterface
{
public:
	using CommandInterface::CommandInterface;
	//StartGameCommand(Menu&);
	virtual void axecute() override;
private:

};
