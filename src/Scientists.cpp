#include "Scientists.h"
#include "Factory/ObjectFactory.h"
#include <memory>
#include "Object.h"
#include <iostream>
#include "Utilities.h"

bool Scientists::m_registered = ObjectFactory<MovingGameObjects>::registerIt(Scientists_t,
	[](int col) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Scientists>(col, DEFULT_START_POINT));
		return lst; });

Scientists::Scientists(int col, int row) 
	: MovingGameObjects(Scientists_t, sf::Vector2f(col, row), 50, std::rand() % 2, "Scientists") //לשנות את הנקודה))
{
	m_sp.setScale(sf::Vector2f(m_direction.x, 1));
	//m_speed = 100;
//	int direction = std::rand() % 2;
//	m_direction = sf::Vector2f(((direction) ? -1 : 1), 1);
//	m_sp.setScale(sf::Vector2f(m_direction.x, 1));//worng direction
	//m_scientistFrames = { sf::IntRect(0, 0, 66.666, 164), sf::IntRect(66.666, 0, 66.666, 164), sf::IntRect(133.333, 0, 66.666, 164) };
}

void Scientists::move(float time)
{
	MovingGameObjects::move(time);

	animate(time);
}



//void Scientists::move_and_change_sprite(float deltaTime, Object* obj)
//{
//	obj->setSpriteRect(m_scientistFrames[m_currentFrame]);
//	
//
//	obj->move(m_direction * m_moveSpeed * deltaTime);
//	m_changeDirectionTimer += deltaTime;
//
////	if (m_changeDirectionTimer >= timeToChangeDirection) {
//	{	changeDirection();
//		m_changeDirectionTimer = 0.0f;
//		//timeToChangeDirection = 1.0f + static_cast<float>(std::rand()) / RAND_MAX * 2.0f; // שינוי כיוון כל 1-3 שניות
//	}
//}


void Scientists::changeDirection()
{
	//int randomDirection = std::rand() % 2;
	//if (randomDirection == 0) 
	//{
	//	m_direction = sf::Vector2f(1.0f, 0.0f); // ימינה
	//}
	//else 
	//{
	//	m_direction = sf::Vector2f(-1.0f, 0.0f); // שמאלה		
	//}
}

