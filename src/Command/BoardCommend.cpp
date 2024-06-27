#include "Command/BoardCommand.h"
#include "Resources.h"
#include "Controller.h"

BoardCommand::BoardCommand(Controller* con, int key)
	: m_controller(con), m_sp(*Resources::getInstance().getTextureButtons(key))
{}

void BoardCommand::setPosition(sf::Vector2f pos)
{
	m_sp.setPosition(pos);
}

bool BoardCommand::contains(sf::Vector2f v2p)
{
	return m_sp.getGlobalBounds().contains(v2p);
}

void BoardCommand::draw(sf::RenderWindow& wind)
{
	wind.draw(m_sp);
}

