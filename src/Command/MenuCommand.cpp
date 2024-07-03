#include "Command/MenuCommand.h"
#include "Menu.h"
#include "Resources.h"

MenuCommand::MenuCommand(Menu* menu, std::string name, int index)
	:m_menu(menu), m_name(name, *Resources::getInstance().getFont(), 40)
{
	m_name.setOutlineColor(sf::Color::Black);
	m_name.setOutlineThickness(2);
	m_sp.setTexture(*Resources::getInstance().getTextureButtons(index));
	m_sp.setOrigin({ m_sp.getGlobalBounds().width / 2 ,m_sp.getGlobalBounds().height / 2 });
	m_name.setOrigin({ m_name.getGlobalBounds().width / 2 ,m_name.getGlobalBounds().height / 2 });
}

//void CommandInterface::setSptire(sf::Vector2f pos, int index)
//{
//	m_sp.setTexture(*Resources::getInstance().getTextureButtons(index));
//	m_sp.setOrigin({m_sp.getGlobalBounds().width / 2 ,m_sp.getGlobalBounds().height / 2 });
//	m_sp.setPosition(pos);
//}

void MenuCommand::setPosition(sf::Vector2f pos)
{
	m_sp.setPosition(pos);
	m_name.setPosition(pos);
}

bool MenuCommand::contains(sf::Vector2f v2p)
{
	if (m_sp.getGlobalBounds().contains(v2p))
	{
		m_name.setScale({ 1.2, 1.2 });
		return true;
	}
	m_name.setScale({ 1, 1 });
	return false;
}

void MenuCommand::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_sp);
	wind.draw(m_name);
}


