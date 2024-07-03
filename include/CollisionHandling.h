#pragma once
#include "Player.h"
#include "Object.h"
#include <map>
#include <typeindex>
#include <SFML/Audio.hpp>

typedef bool (*HitFunctionPtr)(Player&, Object&);
typedef std::map<std::type_index, HitFunctionPtr> HitMap;

class CollisionHandling
{
public:
	static bool processCollision(Player&, Object&);
	static void setVolume(int);
	static void playSound(const sf::SoundBuffer*);

private:
	static HitFunctionPtr lookup(const std::type_index&);
	static HitMap initializeCollisionMap();
	static bool coinCollision(Player&, Object&);
	static bool missileCollision(Player&, Object&);
	static bool laserCollision(Player&, Object&);
	static bool scientistCollision(Player&, Object&);
	static bool speedCollision(Player&, Object&);
	static bool moneyCollision(Player&, Object&);
	static bool powerCollision(Player&, Object&);
	static bool lightCollision(Player&, Object&);

	static sf::Sound m_currSound;

};