#include "Objects/Object.h"
#include <iostream>

Object::Object(const sf::Texture* txture, sf::Vector2f loc, std::string key)
{
	m_sp.setTexture(*txture);
	m_sp.setOrigin(sf::Vector2f(0, txture->getSize().y));
	m_sp.setPosition(loc);

	m_frames = Resources::getInstance().getIntRect(key);
	animate(ANIMATION_RATE);
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
	return m_sp.getGlobalBounds();
}

sf::Transform Object::getTransform() const
{
	return m_sp.getTransform();
}

sf::FloatRect Object::getLocalBounds() const
{
	return m_sp.getLocalBounds();
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

void Object::setNewSprite(std::string key, object_code obj)
{
 	m_sp.setTexture(*Resources::getInstance().getTextureObject(obj));
	m_frames = Resources::getInstance().getIntRect(key);

	m_sp.setOrigin(sf::Vector2f(0, m_frames->at(0).height));

	m_texutre_timer = 0;
	m_curr_frame = -1;

	animate(ANIMATION_RATE);
}

