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
	
private:
	std::unique_ptr<PlayerAnimationState> currentState;


};