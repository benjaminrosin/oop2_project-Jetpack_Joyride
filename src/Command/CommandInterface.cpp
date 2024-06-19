#include "Command/CommandInterface.h"
#include "Menu.h"

CommandInterface::CommandInterface(Menu* menu)
	:m_menu(menu)
{}

void CommandInterface::setSptire(sf::Vector2f pos, int index)
{
	m_sp.setTexture(*Resources::getInstance().getTextureButtons(index));
	m_sp.setOrigin({m_sp.getGlobalBounds().width / 2 ,m_sp.getGlobalBounds().height / 2 });
	m_sp.setPosition(pos);
}

bool CommandInterface::contains(sf::Vector2f v2p)
{
	return m_sp.getGlobalBounds().contains(v2p);
}

void CommandInterface::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_sp);
}


