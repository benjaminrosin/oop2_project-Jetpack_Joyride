#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Missile;

class MissileAnimationState
{
public:
    //MissileAnimationState() {};
    virtual ~MissileAnimationState() {};
   // virtual void enter(Missile*) = 0;
    virtual void update(Missile*, float) = 0;
    //virtual void move(float x) = 0;

  

};
