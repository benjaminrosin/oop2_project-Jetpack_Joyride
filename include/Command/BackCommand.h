#pragma once
#include "Command/BoardCommand.h"

class Controller;

class BackCommand : public BoardCommand
{
public:
	BackCommand(Controller*, int);
	virtual void axecute() override;
private:

};
