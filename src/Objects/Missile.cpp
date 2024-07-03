#include "Objects/Missile.h"
#include "Factory/ObjectFactory.h"
#include "State/AlertMissileState.h"
#include "State/FireMissileState.h"
#include "Objects/Player.h"
#include <iostream>

bool Missile::m_registered = ObjectFactory<MovingGameObjects>::registerIt(Misssile_t,
	[](int col, Player* p) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Missile>(col, p));
		return lst; });


Missile::Missile(int col, Player* p)
	:MovingGameObjects(FirstAlert_t, sf::Vector2f(col, 0), "FirstWarning"),
	m_p2player(p)

{
	setState(std::make_unique<AlertMissileState>(this));

}

void Missile::move(float deltaTime)
{
	m_timer += deltaTime;
	m_currState->update(this, deltaTime);

}

void Missile::setState(std::unique_ptr<MissileAnimationState> state)
{
	m_currState = std::move(state);
}

void Missile::setPositionByPlayer()
{
	int x = m_p2player->getPosition().x + 1000 - m_sp.getGlobalBounds().width;
	int y = m_p2player->getPosition().y;
	if (y < TOP_SCREEN_LIMIT) y = TOP_SCREEN_LIMIT + 50;
	m_p2player->getTransform();

	m_sp.setPosition(sf::Vector2f(x, y));
}
