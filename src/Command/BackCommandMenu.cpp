#include "Command/BackCommandMenu.h"
#include "Menu.h"

BackCommandMenu::BackCommandMenu(Menu* menu, std::string name)
	:MenuCommand(menu, "")
{
	m_sp.setTexture(*Resources::getInstance().getTextureButtons(3));
	//m_s
}

void BackCommandMenu::axecute()
{

}
