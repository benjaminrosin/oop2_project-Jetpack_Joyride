#include "Command/StartGameCommand.h"
#include "Menu.h"

void StartGameCommand::axecute()
{
	m_menu->newGame();
}
