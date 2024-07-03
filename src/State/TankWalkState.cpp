#include "State/TankWalkState.h"
#include "State/TankJumpState.h"
#include "Player.h"

bool TankWalkState::m_registered = PowerupFactory::registerIt(Tank_t,
	[](Player* p) -> std::unique_ptr<PlayerAnimationState> {
		return std::make_unique<TankWalkState>(p); });

TankWalkState::TankWalkState(Player* player)
{
	player->setNewSprite("walking tank", Tank_t);
}

void TankWalkState::update(Player* player, float delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || player->getPosition().y < DEFULT_START_POINT)
	{
		player->setState(std::make_unique<TankJumpState>(player, -350));
	}

	WalkAnimationPlayerState::update(player, delta_time);

}
