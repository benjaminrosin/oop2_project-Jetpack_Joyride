#include "CollisionHandling.h"
//#include <runtime_error>
#include <stdexcept>
#include "Coin.h"
#include "Objects/Missile.h"
#include "Objects/Laser.h"
#include "Scientists.h"
#include "Objects/Light.h"
#include "Gspeed.h"
#include "Gmoney.h"
#include "Gpower.h"
#include "Controller.h"
#include "State/TankJumpState.h"
#include "State/TankWalkState.h"
#include "State/SpeedPlayerState.h"
#include "State/GravityPlayerState.h"
//#include "State/DeadPlayerState.h"
#include <iostream>
#include "Resources.h"
#include <SFML/Audio.hpp>


sf::Sound CollisionHandling::m_currSound;

bool CollisionHandling::processCollision(Player& player, Object& obj)
{
    auto colideFunc = lookup(typeid(obj));
    if (!colideFunc)
    {
        throw std::runtime_error("unknown collision!");
    }
	return colideFunc(player, obj);
}

void CollisionHandling::setVolume(int vol)
{
    m_currSound.setVolume(vol);
}

HitFunctionPtr CollisionHandling::lookup(const std::type_index& obj)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(obj);
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

HitMap CollisionHandling::initializeCollisionMap()
{
    static HitMap colideMap;
    colideMap[typeid(Coin)] = &coinCollision;
    colideMap[typeid(Missile)] = &missileCollision;
    colideMap[typeid(Laser)] = &laserCollision;
    colideMap[typeid(Scientists)] = &scientistCollision;
    colideMap[typeid(Gspeed)] = &speedCollision;
    colideMap[typeid(Gmoney)] = &moneyCollision;
    colideMap[typeid(Gpower)] = &powerCollision;
    colideMap[typeid(Light)] = &lightCollision;

    return colideMap;
}

bool CollisionHandling::coinCollision(Player& player, Object& obj)
{
    Controller::addToCoins();
    playSound(Resources::getInstance().getSoundBuffer(CoinSound_t));
    return true;
}

bool CollisionHandling::missileCollision(Player& player, Object& obj)
{
    playSound(Resources::getInstance().getSoundBuffer(MissileHitSound_t));
    player.playerDie();
    return true;
}

bool CollisionHandling::laserCollision(Player& player, Object& obj)
{
    playSound(Resources::getInstance().getSoundBuffer(LaserHitSound_t));
    player.playerDie();
    return true;
  
}

bool CollisionHandling::scientistCollision(Player&, Object&)
{
    return false;
}


bool CollisionHandling::speedCollision(Player& player, Object&)
{
    playSound(Resources::getInstance().getSoundBuffer(ShieldSpeed_t));

    player.setState(std::make_unique<SpeedPlayerState>(&player));

    return true;
}

bool CollisionHandling::moneyCollision(Player&, Object& obj)
{
    playSound(Resources::getInstance().getSoundBuffer(PiggySound_t));

    Gmoney& gift = dynamic_cast<Gmoney&> (obj);
 
    Controller::addToCoins(gift.getValue());
    return true;
}

bool CollisionHandling::powerCollision(Player& player, Object&)
{
    std::cout << "CollisionHandling::powerCollision - add rand\n";

    playSound(Resources::getInstance().getSoundBuffer(PowerSound_t));
    // adding random between all options
    
    //player.setState(std::make_unique<TankJumpState>(&player));
    player.setState(std::make_unique<GravityPlayerState>(&player));
    

    return true;
}

bool CollisionHandling::lightCollision(Player&, Object&)
{
    return false;
}

void CollisionHandling::playSound(const sf::SoundBuffer* sound)
{
    m_currSound.setBuffer(*sound);
    m_currSound.play();
}

