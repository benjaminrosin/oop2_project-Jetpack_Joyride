#include "MovingGameObjects.h"

MovingGameObjects::MovingGameObjects(object_code obj, sf::Vector2f loc)
	: Object(Resources::getInstance().getTextureObject(obj),
		loc,
		Resources::getInstance().getIntRect(obj))
{
	//m_sp.setTexture(*Resources::getInstance().getTextureObject(obj));
	//m_sp.setTextureRect(Resources::getInstance().getIntRect(obj));
	//m_sp.setPosition(loc);
	//m_sp.setOrigin(sf::Vector2f(0, Resources::getInstance().getIntRect(obj).height));
}

MovingGameObjects::MovingGameObjects(object_code obj, sf::Vector2f loc, float speed, int direction)
	: Object(Resources::getInstance().getTextureObject(obj),
		loc,
		Resources::getInstance().getIntRect(obj)),
	m_speed(speed)
{
	m_direction = sf::Vector2f(((direction) ? 1 : -1), 0);
}

void MovingGameObjects::move(float delta_time)
{
	m_sp.move(m_direction * m_speed * delta_time);
	//change texure
}

//sf::Vector2f MovingGameObjects::getPosition() const
//{
//	return m_sp.getPosition();
//}

//void MovingGameObjects::draw(sf::RenderWindow& wind) const
//{
//	wind.draw(m_sp);
//}

//void MovingGameObjects::setSpriteRect(sf::IntRect rect)
//{
//	m_sp.setTextureRect(rect);
//}

void MovingGameObjects::move(sf::Vector2f move)
{
	m_sp.move(move);
}