#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class MovingGameObjects :public Object {
public:
	MovingGameObjects(object_code, sf::Vector2f);
	MovingGameObjects(object_code, sf::Vector2f, float, int);
	virtual ~MovingGameObjects() {};
	virtual void move(sf::Vector2f move) override;
	virtual void move(float);

protected:
	float m_speed;
	sf::Vector2f m_direction;
};