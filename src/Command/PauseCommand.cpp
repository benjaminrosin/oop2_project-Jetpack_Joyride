#include "Command/PauseCommand.h"
#include "Controller.h"

PauseCommand::PauseCommand(Controller* con, int key)
	:BoardCommand(con, key)
{}

void PauseCommand::axecute()
{
	m_controller->pause();
}
