#include "Scientists.h"

Scientists::Scientists() 
	: MovingObject(Scientists_t, sf::Vector2f(MARGIN, DEFULT_START_POINT)) //לשנות את הנקודה))
{
	changeDirection();
}

void Scientists::move_and_change_sprite(float deltaTime, Object* obj)
{
	m_scientistFrames = { sf::IntRect(0, 0, 66.666, 164), sf::IntRect(66.666, 0, 66.666, 164), sf::IntRect(133.333, 0, 66.666, 164) };
	obj->setSpriteRect(m_scientistFrames[m_currentFrame]);

	obj->moveSprite(m_direction * m_moveSpeed * deltaTime);
	m_changeDirectionTimer += deltaTime;

	if (m_changeDirectionTimer >= timeToChangeDirection) {
		changeDirection();
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

