#pragma once
#include <SFML/Graphics.hpp>
#include "MovingGameObjects.h"

class Scientists:public MovingGameObjects {
public:
	Scientists(int, int);
	virtual ~Scientists() {};
	virtual void move(float) override;

private:
	static bool m_registered;

};