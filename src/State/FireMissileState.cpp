#include <SFML/Graphics.hpp>
#include "State/FireMissileState.h"
#include "objects/Missile.h"
#include <iostream>

void FireMissileState::enter(Missile* missile)
{
	missile->setNewSprite("Missile", Misssile_t);
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
