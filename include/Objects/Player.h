#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Objects/MovingGameObjects.h"
#include "State/PlayerAnimationState.h"
#include "State/TankWalkState.h"



class Player:public MovingGameObjects {
public:
	Player();
	virtual ~Player() {};
	virtual float getHeight() const;
	void setState(std::unique_ptr<PlayerAnimationState>);
	void update(float);
	void playerDie();
	bool avoidCollisions()const;
	void setAvoidStatus(bool);
	virtual void draw(sf::RenderWindow&)const override;
	void move(sf::Vector2f);
	virtual void move(float x) override;

	void updateSpeed(float);
	void setVelocity(float);
	void addVelocity(float);
	const float getVelocity()const;
	const float getSpeed()const;
	const bool isDead()const;
	void dead();
	void rotateSp(float);
	void setPosition(sf::Vector2f);
	void flip(int);
	std::unique_ptr<PlayerAnimationState> getCurrState();
	
private:
	std::unique_ptr<PlayerAnimationState> m_currentState;
	bool m_avoidCollisions = false;
	float m_jumpVelocity;
	bool m_dead = false;

};