#include "Command/NextCommandMenu.h"
#include "Menu.h"

NextCommandMenu::NextCommandMenu(Menu* menu)
	:MenuCommand(menu, "", 3)
{
	m_sp.setColor(sf::Color(40, 250, 40));

}

void NextCommandMenu::axecute()
{
	m_menu->nextSlide(1);
}
