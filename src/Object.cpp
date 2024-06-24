#include "Object.h"
#include <iostream>

Object::Object(const sf::Texture* txture, sf::Vector2f loc, std::string key)
{
	m_sp.setTexture(*txture);
	//m_sp.setTextureRect(rect);
	m_sp.setOrigin(sf::Vector2f(0, txture->getSize().y));
	m_sp.setPosition(loc);

	m_frames = Resources::getInstance().getIntRect(key);
	animate(ANIMATION_RATE);
	//m_texutre_timer.restart();
}

void Object::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_sp);
}

sf::Vector2f Object::getPosition() const
{
	return  m_sp.getPosition();
}

sf::FloatRect Object::getGlobalBounds() const
{
	return sf::FloatRect(m_sp.getGlobalBounds());
}

void Object::animate(float time)
{
	m_texutre_timer += time;

	if (m_texutre_timer >= ANIMATION_RATE)
	{
		m_texutre_timer -= ANIMATION_RATE;
		m_curr_frame = (m_curr_frame + 1) % m_frames->size();
		m_sp.setTextureRect(m_frames->at(m_curr_frame));
	}
}

void Object::setSpriteRect(sf::IntRect rect)
{
	m_sp.setTextureRect(rect);
}

void Object::setNewSprite(std::string key)
{
	m_frames = Resources::getInstance().getIntRect(key);
	m_texutre_timer = 0;
	m_curr_frame = -1;

	animate(ANIMATION_RATE);
}

//const sf::Sprite& Object::getDrawable() const
//{
//	return m_sp;
//}

//void Object::setSpriteRect(sf::IntRect sprite_rect)
//{
//	m_sp.setTextureRect(sprite_rect);
//}

void Object::move(sf::Vector2f v2m)
{
		m_sp.move(v2m);
}

//void Object::setPosition(float x, float y)
//{
//	m_sp.setPosition(x, y);
//}

//sf::Vector2f Object::getPosition() const
//{
//	return m_sp.getPosition();
//}

//void Object::moveSprite(sf::Vector2f move)
//{
//	m_sp.move(move);
//}

