#include "Object.h"

Object::Object(const sf::Texture* txture, sf::Vector2f loc, const sf::IntRect rect)
{
	m_sp.setTexture(*txture);
	m_sp.setTextureRect(rect);
	m_sp.setPosition(loc);

	m_texutre_timer.restart();
}

const sf::Sprite& Object::getDrawable() const
{
	return m_sp;
}

sf::Vector2f Object::get_position() const
{
	return m_sp.getPosition();
}
