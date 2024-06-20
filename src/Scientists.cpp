#include "Scientists.h"
#include "Factory/MovingObjectFactory.h"
#include <memory>
#include "Object.h"
#include <iostream>

bool Scientists::m_registered = MovingObjectFactory::registerIt(Scientists_t, [](int col, int row) -> std::unique_ptr<MovingGameObjects> { return std::make_unique<Scientists>(col, row); });

Scientists::Scientists(int col, int row) 
	: MovingGameObjects(Scientists_t, sf::Vector2f(col, DEFULT_START_POINT)) //לשנות את הנקודה))
{
	int direction = std::rand() % 2;
	m_direction = sf::Vector2f(((direction) ? -1 : 1), 0);
	m_sp.setScale(sf::Vector2f(m_direction.x, 1));//worng direction
	//m_scientistFrames = { sf::IntRect(0, 0, 66.666, 164), sf::IntRect(66.666, 0, 66.666, 164), sf::IntRect(133.333, 0, 66.666, 164) };
}



void Scientists::move_and_change_sprite(float deltaTime, Object* obj)
{
	obj->setSpriteRect(m_scientistFrames[m_currentFrame]);
	

	obj->move(m_direction * m_moveSpeed * deltaTime);
	m_changeDirectionTimer += deltaTime;

//	if (m_changeDirectionTimer >= timeToChangeDirection) {
	{	changeDirection();
		m_changeDirectionTimer = 0.0f;
		//timeToChangeDirection = 1.0f + static_cast<float>(std::rand()) / RAND_MAX * 2.0f; // שינוי כיוון כל 1-3 שניות
	}
}


void Scientists::changeDirection()
{
	int randomDirection = std::rand() % 2;
	if (randomDirection == 0) 
	{
		m_direction = sf::Vector2f(1.0f, 0.0f); // ימינה
	}
	else 
	{
		m_direction = sf::Vector2f(-1.0f, 0.0f); // שמאלה		
	}
}

