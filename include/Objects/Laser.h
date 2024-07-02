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
	void rotate(float);

	virtual sf::FloatRect getLocalBounds() const override;
	//virtual void draw(sf::RenderWindow&)const override;

private:
	
	std::unique_ptr<LaserState> m_currState;
	int m_len;
	int m_angle;
	sf::RectangleShape m_actual_colision;

	static bool m_registered;
};