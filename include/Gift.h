#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(object_code, int, int);

	virtual void open_gift() = 0;
	virtual bool collision(Object&);
	//virtual bool collision(Cat&);
	//virtual bool collision(Mouse&);

};