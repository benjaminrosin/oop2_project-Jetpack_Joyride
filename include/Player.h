#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Player:public Moving_object {
public:
	Player();
	virtual ~Player() {};
	void move_and_change_sprite(float, Object*)override;
	
private:
	

};