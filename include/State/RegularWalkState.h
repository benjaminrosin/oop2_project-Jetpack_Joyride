#pragma once
#include"State/WalkAnimationPlayerState.h"

class RegularWalkState : public WalkAnimationPlayerState {
public:
    virtual void enter(Player*) override;
    virtual void update(Player*, float) override;
    //virtual void draw(Player*, sf::RenderWindow&) override;
    //virtual void jump(Player*) override;

private:

};