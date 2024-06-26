#pragma once
#include <SFML/Graphics.hpp>
#include "State/LaserState.h"

class Laser;

class LaserStaticState : public LaserState {
public:
	virtual void enter();
	virtual void rotate(Laser*, float) override;

private:
	//sf::Sprite m_beam;
	//std::vector<sf::IntRect>* m_frames;
};