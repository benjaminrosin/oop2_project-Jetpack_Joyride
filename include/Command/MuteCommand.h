#pragma once
#include "Command/BoardCommand.h"

class Controller;

class MuteCommand : public BoardCommand
{
public:
	MuteCommand(Controller*, int);
	virtual void axecute() override;
private:
	static bool m_muted;
};
