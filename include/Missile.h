#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Missale:public MovingObject {
public:
	using MovingObject::collision;

	Missale(int, int);
	virtual ~Missale();
	void move_and_change_sprite(float, Object*);
	

	virtual bool collision(Object&)	override;
	virtual bool collision(Missale&)	override;
	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:

};