#pragma once
#include <SFML/Graphics.hpp>

class Laser;

class LaserState {
public:
	virtual ~LaserState() {};
	virtual void rotate(Laser*, float) = 0;

};