#pragma once
#include <SFML/Graphics.hpp>
#include "MovingGameObjects.h"

class Laser:public MovingGameObjects {
public:
	using MovingGameObjects::collision;

	Laser(int, int);
	virtual ~Laser();
	void move_and_change_sprite(float, Object*);
	

	//virtual bool collision(Object&)	override;
	//virtual bool collision(Laser&)	override;
	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:

};