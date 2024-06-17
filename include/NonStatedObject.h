#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class NonStatedObject :public Object {
public:
	NonStatedObject(object_code, sf::Vector2f);
	virtual ~NonStatedObject() {};

	virtual void draw(sf::RenderWindow&) const override;
	virtual void move_and_change_sprite(float, Object*) = 0;
	virtual void setSpriteRect(sf::IntRect) override;

	//virtual bool collision(Object&) = 0;
	//virtual bool collision(Player&) = 0;
	//virtual bool collision(Cat&) = 0;

private:
	sf::Sprite m_sp;
};