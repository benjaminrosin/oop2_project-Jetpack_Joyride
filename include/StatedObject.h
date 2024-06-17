#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class StatedObject :public Object {
public:
	StatedObject(object_code, sf::Vector2f);
	virtual ~StatedObject() {};

	virtual void move_and_change_sprite(float, Object*) = 0;
private:
	std::vector <sf::Sprite> m_sp;
};