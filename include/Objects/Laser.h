#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"
#include "State/LaserState.h"

class Laser :public MovingGameObjects {
public:
	//using StatedObject::collision;

	Laser(int, int);
	virtual ~Laser() {};
	//void move_and_change_sprite(float, Object*);
	virtual void move(float) override;
	//virtual void draw(sf::RenderWindow&)const override;

private:
	//sf::Vector2f calcEndPoint() const;
	//static bool m_registered;
	//sf::Sprite m_end;
	//sf::Sprite m_laser;
	std::unique_ptr<LaserState> m_currState;
	int m_len;
	int m_angle;

	static bool m_register;
};