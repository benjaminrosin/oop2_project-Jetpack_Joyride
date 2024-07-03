#include "State/SpeedPlayerState.h"
#include "State/GravityPlayerState.h"
#include "State/RegularJumpState.h"
#include "State/TankJumpState.h"
#include "Player.h"

SpeedPlayerState::SpeedPlayerState(Player* player, int velocity)
	: JumpAnimationPlayerState(player, SpeedFlame_t, "SpeedFlame"), m_currState(player->getCurrState()), m_player(player)
{
	if (auto state = dynamic_cast<SpeedPlayerState*>(m_currState.get()))
	{
		m_currState = std::move(state->m_currState);
	}
	if (auto state = dynamic_cast<GravityPlayerState*>(m_currState.get()))
	{
		state->normalGravity();
	}

	//player->setAvoidStatus(true);
	player->setVelocity(0);
	player->updateSpeed(400);
	player->rotateSp(45);
	m_timer = 0;
}

SpeedPlayerState::~SpeedPlayerState()
{
	m_timer = 0.0f;
	m_player->updateSpeed(-400);
	m_player->rotateSp(0);
	m_player->setAvoidStatus(false);
	//m_player->setVelocity();
	//m_player.release();
}

void SpeedPlayerState::update(Player* player, float deltaTime)
{
	JumpAnimationPlayerState::update(player, deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player->setVelocity(-400);
	}

	m_timer += deltaTime;
	if (m_timer >= 15)
	{
		m_player->setState(std::move(m_currState));
	}

}

void SpeedPlayerState::draw(const Player* player, sf::RenderWindow& wind)
{
	auto pos = player->getPosition();
	pos.x += getFlameOffset().x;
	pos.y += getFlameOffset().y;
	m_sp.setPosition(pos);

	wind.draw(m_sp);
}
