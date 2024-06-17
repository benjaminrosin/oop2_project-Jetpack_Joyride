#include "StatedObject.h"

StatedObject::StatedObject(object_code obj, sf::Vector2f loc)
	//:m_intRect (Resources::getInstance().getIntRectPtr(obj))
{
	m_sp.push_back(sf::Sprite(*Resources::getInstance().getTextureObject(obj)));
	m_sp[0].setPosition(loc);
	m_sp[0].setTextureRect(Resources::getInstance().getIntRect(obj));
	m_sp[0].setOrigin(sf::Vector2f(0, Resources::getInstance().getIntRect(obj).height));
	//m_sp[0].setOrigin(sf::Vector2f(0, m_sp[0].getGlobalBounds().height));
}

void StatedObject::move(sf::Vector2f v2m)
{
	std::for_each(m_sp.begin(), m_sp.end(), [v2m](auto sp) {sp.move(v2m); });
}

void StatedObject::draw(sf::RenderWindow& wind) const
{
	std::for_each(m_sp.begin(), m_sp.end(), [&wind](auto sp) {wind.draw(sp); });
}

sf::Vector2f StatedObject::getPosition() const
{
	return m_sp[0].getPosition();
}

float StatedObject::getHeight() const
{
	return m_sp[0].getGlobalBounds().height;
}

void StatedObject::setSpriteRect(sf::IntRect rect)
{
	m_sp[0].setTextureRect(rect);
}
