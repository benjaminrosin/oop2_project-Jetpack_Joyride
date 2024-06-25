#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"

class Laser :public MovingGameObjects {
public:
	//using StatedObject::collision;

	Laser(int, int);
	virtual ~Laser() {};
	//void move_and_change_sprite(float, Object*);
	virtual void move(float) override;

private:
	static bool m_registered;
	sf::Sprite m_end;
	std::unique_ptr<LaserState> m_currState;
};