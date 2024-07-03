#pragma once
#include "State/PlayerAnimationState.h"
#include "State/WalkAnimationPlayerState.h"
#include "State/JumpAnimationPlayerState.h"

class Player;
class DeadPlayerState : public PlayerAnimationState {
public:
    DeadPlayerState(Player*);
    virtual void update(Player*, float) override;

};