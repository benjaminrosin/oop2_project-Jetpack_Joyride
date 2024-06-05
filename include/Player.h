#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Player:public Moving_object {
public:
	using Moving_object::collision;

	Player(int, int);
	virtual ~Player();
	void move_and_change_sprite(float, Object*)override;
	

	virtual bool collision(Object&)	override;
	virtual bool collision(Player&)	override;
	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:
	

};