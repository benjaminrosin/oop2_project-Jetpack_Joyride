#include "Command/BackCommand.h"
#include "Controller.h"

BackCommand::BackCommand(Controller* con, int key)
	:BoardCommand(con, key)
{}

void BackCommand::axecute()
{
	m_controller->backToManu();
}
