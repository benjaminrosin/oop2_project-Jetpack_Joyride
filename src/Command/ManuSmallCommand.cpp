#include "Command/MenuSmallCommand.h"
#include "Menu.h"
#include "Resources.h"

MenuSmallCommand::MenuSmallCommand(Menu* menu)
	:m_menu(menu)
{
	m_sp.setTexture(*Resources::getInstance().getTextureButtons(3));
}

void MenuSmallCommand::setPosition(sf::Vector2f pos)
{
	m_sp.setOrigin({ m_sp.getGlobalBounds().width / 2 ,m_sp.getGlobalBounds().height / 2 });
	m_sp.setPosition(pos);
}

bool MenuSmallCommand::contains(sf::Vector2f v2p)
{
	return m_sp.getGlobalBounds().contains(v2p);
}

void MenuSmallCommand::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_sp);

}


