#pragma once
#include "State/JumpAnimationPlayerState.h"


class Player;

class SpeedPlayerState : public JumpAnimationPlayerState {
public:
    SpeedPlayerState(Player*);
    ~SpeedPlayerState();
    virtual void update(Player*, float) override;
    virtual void die(Player*) override {};
    virtual sf::Vector2f getFlameOffset()const override { return { -5, -65 }; };
    virtual void draw(const Player*, sf::RenderWindow&) override;

private:
    float m_timer;
    std::unique_ptr<PlayerAnimationState> m_currState;
    Player* m_player;
};