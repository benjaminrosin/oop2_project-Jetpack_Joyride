#include "NonStatedObject.h"

NonStatedObject::NonStatedObject(object_code obj, sf::Vector2f loc)
{
	m_sp.setTexture(*Resources::getInstance().getTextureObject(obj));
	m_sp.setTextureRect(Resources::getInstance().getIntRect(obj));
	m_sp.setPosition(loc);
	m_sp.setOrigin(sf::Vector2f(0, Resources::getInstance().getIntRect(obj).height));
}

void NonStatedObject::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_sp);
}
