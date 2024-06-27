#pragma once
#include "Command/BoardCommand.h"

class Controller;

class MuteCommand : public BoardCommand
{
public:
	MuteCommand(Controller*, int);
	virtual void axecute() override;
private:
	bool m_muted = false;
};
