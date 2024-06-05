#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"

class Gift : public Static_object
{
public:
	Gift(object_code, int, int);

	virtual void open_gift() = 0;
	virtual bool collision(Object&);
	//virtual bool collision(Cat&);
	//virtual bool collision(Mouse&);

};