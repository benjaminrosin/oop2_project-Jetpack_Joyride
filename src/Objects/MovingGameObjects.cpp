#include "Objects/MovingGameObjects.h"

MovingGameObjects::MovingGameObjects(object_code obj, sf::Vector2f loc, std::string key)
	: Object(Resources::getInstance().getTextureObject(obj),
		loc,
		key)
{
	m_speed = 0;
}

MovingGameObjects::MovingGameObjects(object_code obj, sf::Vector2f loc, float speed, int direction, std::string key)
	: Object(Resources::getInstance().getTextureObject(obj),
		loc,
		key ),
	m_speed(speed)
{
	m_direction = sf::Vector2f(((direction) ? 1 : -1), 0);
}

void MovingGameObjects::move(float delta_time)
{
	m_sp.move(m_direction * m_speed * delta_time);
}

const sf::Sprite MovingGameObjects::getSprite() const
{
	return m_sp;
}
