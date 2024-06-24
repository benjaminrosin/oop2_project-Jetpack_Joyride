#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"

class Object 
{
public:
	Object(const sf::Texture*, sf::Vector2f, std::string);
	virtual ~Object() {};

	//bool checkCollision(Object& obj) const;

	//double dispatch
	//virtual bool collision(Object&) = 0;
	//virtual bool collision(Mouse&) = 0;
	//virtual bool collision(Cat&) = 0;

	virtual void draw(sf::RenderWindow&)const;
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void animate(float);
	//const sf::Sprite& getDrawable() const;
	//virtual sf::Vector2f get_position() const;
	virtual void move(sf::Vector2f) ;
	//virtual void move_and_change_sprite(float, Object*) = 0;
	virtual void setSpriteRect(sf::IntRect);
	virtual void setNewSprite(std::string);

	//virtual void setMove(float, float); //פוגע באובייקטים סטטיים
	//virtual void setPosition(float, float);//פוגע באובייקטים סטטיים
	//virtual sf::Vector2f getPosition() const;//פוגע באובייקטים סטטיים
	//virtual void moveSprite(sf::Vector2f);
protected:
	sf::Sprite m_sp;
private:
	float m_texutre_timer = 0;
	std::vector<sf::IntRect>* m_frames;
	int m_curr_frame = -1;
	//sf::Sound m_sound;

};