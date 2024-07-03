#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Missile;

class MissileAnimationState
{
public:
    virtual ~MissileAnimationState() {};
    virtual void update(Missile*, float) = 0;

};
