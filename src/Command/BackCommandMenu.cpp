#include "Command/BackCommandMenu.h"
#include "Menu.h"

BackCommandMenu::BackCommandMenu(Menu* menu)
	:MenuCommand(menu, "", 3)
{
	//m_sp.setTexture(*Resources::getInstance().getTextureButtons(3));
	//m_sp.setOrigin({ 0.f ,m_sp.getGlobalBounds().height / 2 });
}

	void BackCommandMenu::axecute()
{
	m_menu->backToMenu();
}
