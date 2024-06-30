#pragma once
#include <SFML/Graphics.hpp>
#include "State/LaserState.h"

class Laser;

class LaserRotatingState : public LaserState {
public:
	LaserRotatingState();
	virtual void rotate(Laser*, float) override;

private:
	int m_diraction;

};