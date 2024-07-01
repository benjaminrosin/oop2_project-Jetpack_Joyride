#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"
#include "State/PlayerAnimationState.h"



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
	//virtual sf::Vector2f getPosition() const {};
	virtual void move(sf::Vector2f) override;
	virtual void move(float x) override;

	void updateSpeed(float);
	void setVelocity(float);
	void addVelocity(float);
	const float getVelocity()const;
	const float getSpeed()const;
	const bool isDead()const;
	void dead();
	void rotateSp(float);
	//const std::unique_ptr<PlayerAnimationState>&& getCurrState() const;
	 std::unique_ptr<PlayerAnimationState> getJumpState();
	
private:
	std::unique_ptr<PlayerAnimationState> m_currentState;
	bool m_avoidCollisions = false;
	float m_moveSpeed = 300;
	float m_jumpVelocity = -400;
	bool m_dead = false;

};