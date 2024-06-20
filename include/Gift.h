#pragma once
#include <SFML/Graphics.hpp>
#include "StaticGameObjects.h"

class Gift : public StaticGameObjects
{
public:
	Gift(object_code, int, int);

	virtual void open_gift() = 0;
	//virtual bool collision(Object&);
	//virtual bool collision(Cat&);
	//virtual bool collision(Mouse&);
private:
	//static bool m_registered;

};