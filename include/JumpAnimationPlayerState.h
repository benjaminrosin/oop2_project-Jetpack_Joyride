# pragma once
# include "PlayerAnimationState.h"

class JumpAnimationPlayerState : public PlayerAnimationState {
public:
    public:
        virtual void enter(Player* player) override
        {
            // Set jump animation frames
        }

        virtual void update(Player* player, float deltaTime) override
        {
            // Update jump animation logic
        }

        virtual void draw(Player* player, sf::RenderWindow& window) override
        {
            window.draw(player->sprite);
        }

        virtual void jump(Player* player) override {}

        virtual void walk(Player* player) override
        {
            player->setState(std::make_unique<WalkAnimationPlayerState>());
        }

     /*   virtual void idle(Player* player) override
        {
            player->setState(std::make_unique<IdleAnimation>());
        }*/
    };