#include "Command/PrevCommandMenu.h"
#include "Menu.h"

PrevCommandMenu::PrevCommandMenu(Menu* menu)
	:MenuCommand(menu, "", 3)
{
	m_sp.setScale({ -1.f , 1.f });
	m_sp.setColor(sf::Color(250, 40, 40));
}

void PrevCommandMenu::axecute()
{
	//m_menu->backToMenu();
}
