#pragma once
#include <SFML/Graphics.hpp>

class Laser;

class LaserState {
public:
	virtual void enter() = 0;
	//void draw(sf::RenderWindow&);
	virtual void rotate(Laser*, float) = 0;

private:
	//sf::Sprite m_beam;
	//std::vector<sf::IntRect>* m_frames;
};