#include "Objects/Missile.h"
#include "Factory/ObjectFactory.h"
#include "State/AlertMissileState.h"
#include "State/FireMissileState.h"
#include "Player.h"
#include <iostream>

bool Missile::m_registered = ObjectFactory<MovingGameObjects>::registerIt(Misssile_t,
	[](int col, int row, Player* p) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Missile>(col, row, p));
		return lst; });


Missile::Missile(int col, int row, Player* p)
	:MovingGameObjects(FirstAlert_t, sf::Vector2f(col, row), "FirstWarning"),
	m_p2player(p)

{
	setState(std::make_unique<AlertMissileState>(this));
	m_sp.setOrigin(sf::Vector2f(0, m_sp.getGlobalBounds().height/2));
	//m_currState->enter(this);
}



void Missile::move(float deltaTime)
{
	m_timer += deltaTime;

	m_currState->update(this, deltaTime);

}

void Missile::setState(std::unique_ptr<MissileAnimationState> state)
{
	m_currState = std::move(state);
	//m_currState->enter(this);
}

void Missile::setPositionByPlayer()
{
	int x = m_p2player->getPosition().x + 1000 - m_sp.getGlobalBounds().width;
	int y = m_p2player->getPosition().y;

	m_sp.setPosition(sf::Vector2f(x, y));
}

//void Missile::playSound(const sf::SoundBuffer* sound)
//{
//	m_currSound.setBuffer(*sound);
//	m_currSound.play();
//}