#pragma once
#include"State/WalkAnimationPlayerState.h"

class TankWalkState : public WalkAnimationPlayerState {
public:
    TankWalkState(Player*);
    //virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    //virtual PlayerAnimationState* jump(Player*) override;

    //virtual void draw(Player*, sf::RenderWindow&) override;
    //virtual void jump(Player*) override;

private:

};