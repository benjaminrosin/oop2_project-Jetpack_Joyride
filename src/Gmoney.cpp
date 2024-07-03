#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Gmoney.h"
#include "Factory/ObjectFactory.h"
#include "Utilities.h"

bool Gmoney::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gmoney_t,
	[](int col) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gmoney>(col, randomY()));
		return lst; });


Gmoney::Gmoney(int col, int row)
	:Gift(Gmoney_t, col, row, "Gmoney")
{
	m_value = 50 + (rand() % 10) * 10;
	m_text.setString(std::to_string(m_value));

	m_text.setCharacterSize(30);
	m_text.setFont(*Resources::getInstance().getFont());
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(2);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	
	auto pos = m_sp.getPosition();
	pos.x += m_sp.getGlobalBounds().width / 2;
	pos.y -= m_sp.getGlobalBounds().height / 2;
	m_text.setPosition(pos);
}

void Gmoney::draw(sf::RenderWindow& wind) const
{
	Object::draw(wind);
	wind.draw(m_text);

}

int Gmoney::getValue() const
{
	return m_value;
}

void Gmoney::open_gift()
{
}
