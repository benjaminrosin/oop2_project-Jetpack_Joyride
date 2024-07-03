#pragma once
#include"State/WalkAnimationPlayerState.h"
#include "Factory/PowerupFactory.h"

class GravityPlayerState : public WalkAnimationPlayerState {
public:
    GravityPlayerState(Player*, int = GRAVITY);
    ~GravityPlayerState();
    //virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    void normalGravity();

private:

    int m_gravity;
    float m_timer = 0;
    Player* m_player;
    static bool m_registered;
    void flip();
};