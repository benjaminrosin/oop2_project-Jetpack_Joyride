#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"

//forward decleration
//class Cat;


class Object 
{
public:
	Object(const sf::Texture*, int, int);
	virtual ~Object();

	bool checkCollision(Object& obj) const;

	//double dispatch
	virtual bool collision(Object&) = 0;
	//virtual bool collision(Mouse&) = 0;
	//virtual bool collision(Cat&) = 0;

	virtual void draw(sf::RenderWindow&)const;
	void set_position(sf::Vector2f);
	sf::Vector2f get_position() const;
	virtual void move_and_change_sprite(sf::Vector2f);
	sf::Sprite get_sprite()const;
	void set_color(sf::Color);

private:
	sf::Sprite m_sp;
	sf::clock m_texutre_timer;
	sf::Sound m_sound;

};