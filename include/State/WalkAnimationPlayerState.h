# pragma once
#include "State/PlayerAnimationState.h"
#include "State/JumpAnimationPlayerState.h"
#include "Resources.h"

class Player;
class WalkAnimationPlayerState : public PlayerAnimationState {
public:
    virtual void update(Player*, float) = 0;

};