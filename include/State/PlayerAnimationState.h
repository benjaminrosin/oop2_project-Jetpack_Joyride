#pragma once
#include <SFML/Graphics.hpp>

class Player;

class PlayerAnimationState {

public:
    virtual void enter(Player*) = 0;
    virtual void update(Player*, float) = 0;
    //virtual void draw(Player*, sf::RenderWindow&);
    virtual void jump(Player*) = 0;
    //virtual void walk(Player*) = 0;
    //virtual void idle(Player*) = 0;
    virtual ~PlayerAnimationState() = default;
};