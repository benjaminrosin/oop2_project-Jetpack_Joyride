#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"

class Object 
{
public:
	Object(const sf::Texture*, sf::Vector2f, sf::IntRect);
	virtual ~Object() {};

	//bool checkCollision(Object& obj) const;

	//double dispatch
	//virtual bool collision(Object&) = 0;
	//virtual bool collision(Mouse&) = 0;
	//virtual bool collision(Cat&) = 0;

	//virtual void draw(sf::RenderWindow&)const;
	const sf::Sprite& getDrawable() const;
	sf::Vector2f get_position() const;
	virtual void move_and_change_sprite(float, Object*) = 0;

private:
	sf::Sprite m_sp;
	sf::Clock m_texutre_timer;
	//sf::Sound m_sound;

};