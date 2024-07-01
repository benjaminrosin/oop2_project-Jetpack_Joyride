#include "State/AlertMissileState.h"
#include "State/FireMissileState.h"
#include "objects/Missile.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "CollisionHandling.h"

AlertMissileState::AlertMissileState(Missile* missile)
{
	missile->setNewSprite("FirstWarning", FirstAlert_t);
	CollisionHandling::playSound(Resources::getInstance().getSoundBuffer(MissileAlarmSound_t));

}

void AlertMissileState::update(Missile* missile, float deltaTime)
{
	m_timer += deltaTime;

	missile->setPositionByPlayer();
	missile->animate(deltaTime);

	if (m_timer > 2 && m_firstTime)
	{
		missile->setNewSprite("SecondWarning", SecondAlert_t);
		m_firstTime = false;
	}
	if (m_timer > 3)
	{
		std::cout << "fire\n";
		missile->setState(std::make_unique<FireMissileState>(missile));
	}
}

//
//void AlertMissileState::move(float deltaTime)
//{
//
//}
