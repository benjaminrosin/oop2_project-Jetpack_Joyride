#pragma once
#include "Player.h"

class PlayerAnimationState {

    virtual void enter(Player*) = 0;
    virtual void update(Player*, float) = 0;
    virtual void draw(Player*, sf::RenderWindow&) = 0;
    virtual void jump(Player*) = 0;
    virtual void run(Player*) = 0;
    //virtual void idle(Player*) = 0;
    virtual ~PlayerAnimationState() = default;
};