#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Object.h"
#include "Resources.h"


class MovingGameObjects :public Object
{
public:
	MovingGameObjects(object_code, sf::Vector2f, std::string);
	MovingGameObjects(object_code, sf::Vector2f, float, int, std::string);
	virtual ~MovingGameObjects() {};
	virtual void move(float) = 0;
	virtual const sf::Sprite getSprite() const;

protected:
	float m_speed;
	sf::Vector2f m_direction;
	float m_animationTimer = 0;
};