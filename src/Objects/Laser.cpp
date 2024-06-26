#include "Objects/Laser.h"
#include "Factory/ObjectFactory.h"
#include "Resources.h"
#include <iostream>
#include "State/LaserStaticState.h"
#include "State/LaserRotatingState.h"

bool Laser::m_register = ObjectFactory<MovingGameObjects>::registerIt(Laser_t,
	[](int col, int row) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Laser>(col, row));
		return lst; });

Laser::Laser(int col, int row)
	: MovingGameObjects(Laser_t, sf::Vector2f(col, row), "Laser") //לשנות את הנקודה))
{
	m_sp.setOrigin({m_sp.getGlobalBounds().width / 2, m_sp.getGlobalBounds().height / 2});
	//m_end.setTexture(*m_sp.getTexture());
	//m_end.setTextureRect(m_sp.getTextureRect());
	
	//m_sp.setScale(1, -1);

	m_angle = (rand() % 18) * 10;
	//m_end.rotate(m_angle);
	m_sp.rotate(m_angle);

	//calc enp point
	//m_end.setPosition(calcEndPoint());

	//m_end.setColor(sf::Color::Green); //for debug

	m_len = 100 + (rand() % 30) * 10;

	//scaling sprite
	int state = rand() % 2;
	//((state) ? m_currState = std::make_unique<LaserStaticState>() : m_currState = std::make_unique<LaserRotatingState>());
	m_currState = std::make_unique<LaserRotatingState>();
	m_currState->enter();
}

void Laser::move(float time)
{
	m_currState->rotate(this, time);
	animate(time);

	//m_end.setTextureRect(m_sp.getTextureRect());
}

void Laser::rotate(float angle)
{
	m_sp.rotate(angle);
}

//void Laser::draw(sf::RenderWindow& wind) const
//{
//	m_currState->draw(wind);
//	wind.draw(m_sp);
//	//wind.draw(m_end);
//}
//
//sf::Vector2f Laser::calcEndPoint() const
//{
//	float angleRadians = m_angle * (PI / 180.0f);
//
//		// Calculate the end point
//	float endX = m_sp.getPosition().x - m_len * std::cos(angleRadians);
//	float endY = m_sp.getPosition().y - m_len * std::sin(angleRadians);
//
//	std::cout << "original: " << m_sp.getPosition().x << " , " << m_sp.getPosition().y <<'\n';
//	std::cout << "new one:  " << endX << " , " << endY <<'\n';
//	std::cout << "--------------------\n";
//
//	return sf::Vector2f(endX, endY);
//
//}
