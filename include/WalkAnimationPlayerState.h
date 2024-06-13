# pragma once
# include "PlayerAnimationState.h"

class WalkAnimationPlayerState : public PlayerAnimationState {
public:
    virtual void enter(Player* player) override
    {
        // Set walk animation frames
    }

    virtual void update(Player* player, float deltaTime) override
    {
        // Update walk animation logic
    }

    virtual void draw(Player* player, sf::RenderWindow& window) override
    {
        window.draw(player->sprite);
    }

    virtual void jump(Player* player) override
    {
        player->setState(std::make_unique<JumpAnimationPlayerState>());
    }

    virtual void walk(Player* player) override {}

    /*virtual void idle(Player* player) override
    {
        player->setState(std::make_unique<IdleAnimation>());
    }*/
};