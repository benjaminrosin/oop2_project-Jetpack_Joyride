#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class NonStatedObject :public Object {
public:
	NonStatedObject(object_code, int, int);
	virtual ~NonStatedObject();

	virtual bool collision(Object&) = 0;
	//virtual bool collision(Player&) = 0;
	//virtual bool collision(Cat&) = 0;

private:

};