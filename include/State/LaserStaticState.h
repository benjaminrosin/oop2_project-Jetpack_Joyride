#pragma once
#include <SFML/Graphics.hpp>
#include "State/LaserState.h"

class Laser;

class LaserStaticState : public LaserState {
public:
	virtual void rotate(Laser*, float) override {};	//relevant only for rotating

};