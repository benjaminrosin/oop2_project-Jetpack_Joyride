#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

class Gift : public GameObjects
{
public:
	Gift(object_code, int, int);

	virtual void open_gift() = 0;
	//virtual bool collision(Object&);
	//virtual bool collision(Cat&);
	//virtual bool collision(Mouse&);

};