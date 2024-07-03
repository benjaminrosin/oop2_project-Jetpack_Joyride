#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"
#include "State/LaserState.h"

class Laser :public MovingGameObjects {
public:
	Laser(int, int);
	virtual ~Laser() {};
	virtual void move(float) override;
	void rotate(float);
	virtual sf::FloatRect getLocalBounds() const override;

private:
	std::unique_ptr<LaserState> m_currState;
	int m_len;
	int m_angle;
	sf::RectangleShape m_actual_colision;

	static bool m_registered;
};