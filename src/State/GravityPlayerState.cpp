#include "State/GravityPlayerState.h"
#include "Player.h"

bool GravityPlayerState::m_registered = PowerupFactory::registerIt(Gravity_t,
	[](Player* p) -> std::unique_ptr<PlayerAnimationState> {
		return std::make_unique<GravityPlayerState>(p); });


GravityPlayerState::GravityPlayerState(Player* player, int gravity)
	:m_gravity(gravity), m_player(player)
{
	player->setNewSprite("Gravity", Gravity_t);
	player->setVelocity(500);

}

GravityPlayerState::~GravityPlayerState()
{
	normalGravity();
}

void GravityPlayerState::update(Player* player, float deltaTime)
{
	m_timer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_timer > 0.25)
	{
		flip();
	}
	else if((m_gravity > 0 &&(player->getPosition().y < DEFULT_START_POINT )) ||
			(m_gravity < 0 &&( player->getPosition().y > TOP_SCREEN_LIMIT)))
	{
		player->move(sf::Vector2f(deltaTime, m_gravity/GRAVITY * deltaTime));
	}
	else {
		WalkAnimationPlayerState::update(player, deltaTime);
	}
}

void GravityPlayerState::normalGravity()
{
	if (m_gravity < 0)
	{
		flip();
		m_player->setPosition(m_player->getPosition() + sf::Vector2f(0, 10 + m_player->getGlobalBounds().height));
	}
}

void GravityPlayerState::flip()
{
	m_gravity = -m_gravity;
	m_player->flip(m_gravity / GRAVITY);
	m_timer = 0;
}
