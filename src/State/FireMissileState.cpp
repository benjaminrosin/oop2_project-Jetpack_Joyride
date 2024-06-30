#include <SFML/Graphics.hpp>
#include "State/FireMissileState.h"
#include "objects/Missile.h"
#include <iostream>
#include <SFML/Audio.hpp>

FireMissileState::FireMissileState(Missile* missile)
{
	missile->setNewSprite("Missile", Misssile_t);
	missile->playSound(Resources::getInstance().getSoundBuffer(MissileLaunchSound_t));
	
}

void FireMissileState::update(Missile* missile, float deltaTime)
{
	auto pos = missile->getPosition();
	pos.x -= deltaTime * MISSILE_SPEED;

	auto move = sf::Vector2f(-deltaTime * MISSILE_SPEED, 0);
	missile->move(move);
	missile->animate(deltaTime);
	//calc the move

}

//void FireMissileState::move(float deltaTime)
//{
//
//}
