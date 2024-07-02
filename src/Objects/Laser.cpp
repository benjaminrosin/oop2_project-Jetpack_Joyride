#include "Objects/Laser.h"
#include "Factory/ObjectFactory.h"
#include "Resources.h"
#include <iostream>
#include "State/LaserStaticState.h"
#include "State/LaserRotatingState.h"

bool Laser::m_registered = ObjectFactory<MovingGameObjects>::registerIt(Laser_t,
	[](int col, int row) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Laser>(col, row));
		return lst; });

Laser::Laser(int col, int row)
	: MovingGameObjects(Laser_t, sf::Vector2f(col, row), "Laser") //לשנות את הנקודה))
{
	m_sp.setOrigin({m_sp.getGlobalBounds().width / 2, m_sp.getGlobalBounds().height / 2});
	
	m_actual_colision.setSize({ 50, 350 });
	m_actual_colision.setOrigin({ m_actual_colision.getGlobalBounds().width / 2, m_actual_colision.getGlobalBounds().height / 2 });

	m_angle = (rand() % 18) * 10;
	rotate(m_angle);


	int state = rand() % 2;
	((state) ? m_currState = std::make_unique<LaserStaticState>() : m_currState = std::make_unique<LaserRotatingState>());
}

void Laser::move(float time)
{
	m_currState->rotate(this, time);
	animate(time);
}

void Laser::rotate(float angle)
{
	m_sp.rotate(angle);
	m_actual_colision.rotate(angle);
}

sf::FloatRect Laser::getLocalBounds() const
{
	return m_actual_colision.getLocalBounds();
}

