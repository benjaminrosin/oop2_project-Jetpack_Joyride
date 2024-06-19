#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class GameObjects :public Object {
public:
	GameObjects(object_code, sf::Vector2f);
	virtual ~GameObjects() {};

	//virtual sf::Vector2f getPosition() const override;
	//virtual void draw(sf::RenderWindow&) const override;
	virtual void move_and_change_sprite(float, Object*) = 0;
	//virtual void setSpriteRect(sf::IntRect) override;
	virtual void move(sf::Vector2f move) override;

	//virtual bool collision(Object&) = 0;
	//virtual bool collision(Player&) = 0;
	//virtual bool collision(Cat&) = 0;

private:
	//sf::Sprite m_sp;
};