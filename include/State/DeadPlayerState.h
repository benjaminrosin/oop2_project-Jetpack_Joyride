#pragma once
#include "State/PlayerAnimationState.h"
#include "State/WalkAnimationPlayerState.h"
#include "State/JumpAnimationPlayerState.h"

class Player;
class DeadPlayerState : public PlayerAnimationState {
public:
    DeadPlayerState(Player*);
    virtual void update(Player*, float) override;

protected: 
    //float m_jumpVelocity =400;
    //float m_gravity= 400.0f;
    
};