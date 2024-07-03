#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class StaticGameObjects :public Object {
public:
	StaticGameObjects(object_code obj, sf::Vector2f loc, std::string key)
		: Object(Resources::getInstance().getTextureObject(obj), loc, key) {};
};