#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Moving_object :public Object {
public:
	Moving_object(object_code, sf::Vector2f);
	virtual ~Moving_object() {};

	virtual void move_and_change_sprite(float, Object*) = 0;

private:

};