#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class MovingGameObjects :public Object {
public:
	MovingGameObjects(object_code, sf::Vector2f);

	virtual ~MovingGameObjects() {};
	virtual void move(sf::Vector2f move) override;

private:

};