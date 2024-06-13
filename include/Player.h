#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingObject.h"
#include "PlayerAnimationState.h"



class Player:public MovingObject {
public:
	Player();
	virtual ~Player() {};
	void move_and_change_sprite(float, Object*)override;

	void setState(std::unique_ptr<PlayerAnimationState>);
	void update(float);
	void draw(sf::RenderWindow&);
	void jump();
	void walk();

	
private:
	std::unique_ptr<PlayerAnimationState> m_currentState;
};