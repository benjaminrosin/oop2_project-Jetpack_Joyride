#pragma once
#include "State/JumpAnimationPlayerState.h"


class Player;

class SpeedPlayerState : public JumpAnimationPlayerState {
public:
    SpeedPlayerState(Player*);
    ~SpeedPlayerState();
    virtual void update(Player*, float) override;
    virtual void die(Player*) override {};
    virtual int getXOffset()const { return 10; };

private:
    float m_timer;
    std::unique_ptr<PlayerAnimationState> m_currState;
    Player* m_player;
};