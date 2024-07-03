#include "Command/BackCommandMenu.h"
#include "Menu.h"

BackCommandMenu::BackCommandMenu(Menu* menu)
	:MenuCommand(menu, "", 3)
{}

	void BackCommandMenu::axecute()
{
	m_menu->backToMenu();
}
