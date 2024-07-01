#pragma once
#include "Player.h"
#include "Object.h"
#include <map>
#include <typeindex>
#include <SFML/Audio.hpp>

typedef bool (*HitFunctionPtr)(Player&, Object&);//maybe we need to erase object
typedef std::map<std::type_index, HitFunctionPtr> HitMap;
//typedef (bool*)(Object&) HitFunctionPtr;

class CollisionHandling
{
public:
	static bool processCollision(Player&, Object&);//לבדוק אם אפשר להוסיף קונסט בארגומנטים
	static void setVolume(int);
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


	static void playSound(const sf::SoundBuffer*);

	static sf::Sound m_currSound;

	//static bool pixelPerfectCollision(const sf::Sprite&, const sf::Sprite&);
	//static std::vector<uint8_t> createBitMask(const sf::Texture& texture) 


};