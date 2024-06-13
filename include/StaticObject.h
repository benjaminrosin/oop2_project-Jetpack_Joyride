#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class StaticObject :public Object {
public:
	StaticObject(object_code, int, int);
	virtual ~StaticObject();

	virtual bool collision(Object&) = 0;
	virtual bool collision(Player&) = 0;
	virtual bool collision(Cat&) = 0;

private:

};