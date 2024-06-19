#pragma once
#include "Player.h"
#include "GameObjects.h"
#include <map>
#include <typeindex>

typedef bool (*HitFunctionPtr)(Player&, GameObjects&);
typedef std::map<std::type_index, HitFunctionPtr> HitMap;
//typedef (bool*)(GameObjects&) HitFunctionPtr;

class CollisionHandling
{
public:
	static void processCollision(Player&, GameObjects&);//לבדוק אם אפשר להוסיף קונסט בארגומנטים
private:
	static HitFunctionPtr lookup(const std::type_index&);
	static HitMap initializeCollisionMap();
	static bool coinCollision(Player&, GameObjects&);
	//static bool missileCollision(Player&, GameObjects&);
	//static bool laserCollision(Player&, GameObjects&);
	static bool scientistCollision(Player&, GameObjects&);
	static bool shieldCollision(Player&, GameObjects&);
	static bool speedCollision(Player&, GameObjects&);
	static bool moneyCollision(Player&, GameObjects&);
	static bool powerCollision(Player&, GameObjects&);










};