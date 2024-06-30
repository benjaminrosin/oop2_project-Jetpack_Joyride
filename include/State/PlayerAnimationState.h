#pragma once
#include <SFML/Graphics.hpp>

class Player;

class PlayerAnimationState {

public:
    virtual void enter(Player*) = 0;
    virtual void update(Player*, float) = 0;
    virtual void die(Player*);
    virtual void draw(const Player*, sf::RenderWindow&) {}; //relevant only for jumping
   /// virtual void jump(Player*) = 0;
    //virtual void walk(Player*) = 0;
    //virtual void idle(Player*) = 0;
    virtual ~PlayerAnimationState() = default;

private:
    float m_jumpVelocity = 400;
    float m_gravity = 400;
};