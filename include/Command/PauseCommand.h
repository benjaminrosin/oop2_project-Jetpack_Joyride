#pragma once
#include "Command/BoardCommand.h"

class Controller;

class PauseCommand : public BoardCommand
{
public:
	PauseCommand(Controller*, int);
	virtual void axecute() override;
private:
	
};
