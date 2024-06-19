#include "Command/StartGameCommand.h"
#include "Menu.h"

//StartGameCommand::StartGameCommand(Menu& menu)
//	//: CommandInterface(menu)
//{
//}

void StartGameCommand::axecute()
{
	m_menu->newGame();
}
