#include "Objects/Scientists.h"
#include "Factory/ObjectFactory.h"
#include <memory>
#include "Objects/Object.h"
#include <iostream>
#include "Utilities.h"

bool Scientists::m_registered = ObjectFactory<MovingGameObjects>::registerIt(Scientists_t,
	[](int col) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Scientists>(col, DEFULT_START_POINT));
		return lst; });

Scientists::Scientists(int col, int row) 
	: MovingGameObjects(Scientists_t, sf::Vector2f(col, row), 50, std::rand() % 2, "Scientists") 
{
	m_sp.setScale(sf::Vector2f(m_direction.x, 1));
}

void Scientists::move(float time)
{
	MovingGameObjects::move(time);

	animate(time);
}