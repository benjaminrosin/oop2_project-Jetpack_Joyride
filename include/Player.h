#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "StatedObject.h"
#include "PlayerAnimationState.h"



class Player:public StatedObject {
public:
	Player();
	virtual ~Player() {};
	void move_and_change_sprite(float, Object*)override;

	void setState(std::unique_ptr<PlayerAnimationState>);
	void update(float);
	//void draw(sf::RenderWindow&);
	void jump();
	void walk();
	void handleSpaceRelease();

	
private:
	std::unique_ptr<PlayerAnimationState> m_currentState;
};