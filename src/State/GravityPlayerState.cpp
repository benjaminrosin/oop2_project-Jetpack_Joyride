#include "State/GravityPlayerState.h"
#include "Player.h"

GravityPlayerState::GravityPlayerState(Player* player)
{
	player->setNewSprite("Gravity", Gravity_t);
	//set scale
}

void GravityPlayerState::update(Player* player, float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//set state to -1 gravity
	}
	else if(player->getPosition().y < DEFULT_START_POINT)
	{
		//fall down
		std::cout << "jump\n";
	}

	WalkAnimationPlayerState::update(player, deltaTime);
}
