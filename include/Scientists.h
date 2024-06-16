#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Scientists:public MovingObject {
public:
	//using MovingObject::collision;

	Scientists();
	//virtual ~Scientists();
	void move_and_change_sprite(float, Object*);
	void changeDirection();
		
		
	/*virtual bool collision(Object&)	override;
	virtual bool collision(Scientists&)	override;*/

	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:
	float m_moveSpeed = 100.0f; // מהירות תנועה
	std::vector<sf::IntRect> m_scientistFrames;
	int m_currentFrame = 0;
	float m_changeDirectionTimer = 0.0f;
	sf::Vector2f m_direction;
	float timeToChangeDirection = 1.5f; // זמן בשניות לשינוי כיוון
};