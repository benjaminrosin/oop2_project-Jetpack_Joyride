#pragma once
#include <SFML/Graphics.hpp>

class Laser;

class LaserState {
public:
	void enter();
	//void draw(sf::RenderWindow&);
	void move(Laser*);

private:
	//sf::Sprite m_beam;
	//std::vector<sf::IntRect>* m_frames;
};