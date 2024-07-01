#include "State/SpeedPlayerState.h"
#include "State/RegularJumpState.h"
#include "State/TankJumpState.h"
#include "Player.h"

float SpeedPlayerState::m_timer = 0.0f; 

SpeedPlayerState::SpeedPlayerState(Player* player)
	: JumpAnimationPlayerState(player), m_currState(player->getJumpState()), m_player(player)
{
	//player->setAvoidStatus(true);
	player->updateSpeed(400);
	player->rotateSp(45);
	m_timer = 0;
}

SpeedPlayerState::~SpeedPlayerState()
{
	m_timer = 0.0f;
	m_player->updateSpeed(-400);
	m_player->rotateSp(0);
	//m_player.release();
}

void SpeedPlayerState::update(Player* player, float deltaTime)
{
	std::cout << "speed: " << m_timer << '\n';

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player->setVelocity(-400);
	}
	else if (player->getPosition().y + player->getHeight() > DEFULT_START_POINT)
	{
		player->setVelocity(-GRAVITY*deltaTime);
			//setVelocity(0);
	}

	JumpAnimationPlayerState::update(player, deltaTime);

	m_timer += deltaTime;
	if (m_timer >= 15)
	{
		//player->setAvoidStatus(false);
		player->setState(std::move(m_currState));

	}

}