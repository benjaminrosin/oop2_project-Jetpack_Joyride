#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"

class Object 
{
public:
	Object(const sf::Texture*, sf::Vector2f, std::string);
	virtual ~Object() {};

	virtual void draw(sf::RenderWindow&)const;
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getGlobalBounds() const;
	virtual sf::Transform getTransform() const;
	virtual sf::FloatRect getLocalBounds() const;
	virtual void animate(float);
	virtual void setSpriteRect(sf::IntRect);
	virtual void setNewSprite(std::string, object_code);

protected:
	sf::Sprite m_sp;
private:
	float m_texutre_timer = 0;
	std::vector<sf::IntRect>* m_frames;
	int m_curr_frame = -1;

};