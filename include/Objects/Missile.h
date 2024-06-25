#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"

class Missile:public MovingGameObjects {
public:
	//using StatedObject::collision;

	Missile(int, int);
	virtual ~Missile();
	//void move_and_change_sprite(float, Object*);
	
private:
	static bool m_registered;
	//sf::Sprite m_firstAlert;
	//sf::Sprite m_SecondAlert;
	std::unique_ptr<MissileState> m_currState;
	int m_heightPlayer;
};