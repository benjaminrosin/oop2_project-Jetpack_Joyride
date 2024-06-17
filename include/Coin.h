#pragma once
#include <SFML/Graphics.hpp>
#include "NonStatedObject.h"

class Coin:public NonStatedObject {
public:
	//using NonStatedObject::collision;

	Coin(int, int);
	virtual ~Coin(){};
	void move_and_change_sprite(float, Object*);
	

	//virtual bool collision(Object&)	override;
	//virtual bool collision(Coin&)	override;
	//virtual bool collision(Cat&)	override;
	//virtual bool collision(Cheese&)	override;
	//virtual bool collision(Door&)	override;
	//virtual bool collision(Gift&)	override;
	//virtual bool collision(Key&)	override;

private:
	static bool m_registered;

};