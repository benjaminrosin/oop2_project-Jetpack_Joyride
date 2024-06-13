#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class MovingObject :public Object {
public:
	MovingObject(object_code, sf::Vector2f);
	virtual ~MovingObject() {};

	virtual void move_and_change_sprite(float, Object*) = 0;

private:

};