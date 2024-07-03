#include <SFML/Graphics.hpp>
#include "State/FireMissileState.h"
#include "objects/Missile.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "CollisionHandling.h"

FireMissileState::FireMissileState(Missile* missile)
{
	missile->setNewSprite("Missile", Misssile_t);
	CollisionHandling::playSound(Resources::getInstance().getSoundBuffer(MissileLaunchSound_t));
	
}

void FireMissileState::update(Missile* missile, float deltaTime)
{
	auto move = sf::Vector2f(-deltaTime * MISSILE_SPEED, 0);
	missile->move(move);
	missile->animate(deltaTime);

}
