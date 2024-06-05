#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Moving_object :public Object {
public:
	Moving_object(object_code, int, int);
	virtual ~Moving_object();

	virtual void move_and_change_sprite(float, Object*) = 0;

	virtual bool collision(Object&) =0;
	//virtual bool collision(Mouse&) =0;
	//virtual bool collision(Cat&) =0;
	//virtual bool collision(Cheese&)	{ return false; }
	//virtual bool collision(Door&);
	//virtual bool collision(Gift&) { return false; }
	//virtual bool collision(Key&) { return false; }
	//virtual bool collision(Wall&);

private:

};