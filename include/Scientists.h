#pragma once
#include <SFML/Graphics.hpp>
#include "MovingGameObjects.h"

class Scientists:public MovingGameObjects {
public:
	//using StatedObject::collision;

	Scientists(int, int);
	virtual ~Scientists() {};
	void move_and_change_sprite(float, Object*);


private:
	void changeDirection();

	float m_moveSpeed = 100.0f; // מהירות תנועה
	std::vector<sf::IntRect> m_scientistFrames;
	int m_currentFrame = 0;
	float m_changeDirectionTimer = 1.5;
	sf::Vector2f m_direction;
	static bool m_registered;

};