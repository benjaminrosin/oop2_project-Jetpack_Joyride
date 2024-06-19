#include "Command/HighScoreCommand.h"
#include "Menu.h"

//HighScoreCommand::HighScoreCommand(Menu& menu)
	//:CommandInterface(menu)
//{}

void HighScoreCommand::axecute()
{
	m_menu->highScore();
}
