#include "State/SpeedPlayerState.h"
#include "State/RegularJumpState.h"
#include "State/TankJumpState.h"
#include "Player.h"


SpeedPlayerState::SpeedPlayerState(Player* player)
	: JumpAnimationPlayerState(player, SpeedFlame_t, "SpeedFlame"), m_currState(player->getCurrState()), m_player(player)
{
	if (auto state = dynamic_cast<SpeedPlayerState*>(m_currState.get()))
	{
		m_currState = std::move(state->m_currState);
	}

	//player->setAvoidStatus(true);
	player->setVelocity(-400);
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
	//sf::FloatRect newPlayerBounds = obj.getTransform().getInverse().transformRect(m_player->getGlobalBounds());

	//sf::FloatRect newPlayerpos = player->getTransform().getInverse().transformRect(player->getGlobalBounds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player->setVelocity(-400);
	}
	else if (player->getPosition().y + player->getHeight() > DEFULT_START_POINT)
	//else if (newPlayerpos.height > DEFULT_START_POINT)
	{
		//player->setVelocity(-GRAVITY*deltaTime);
		player->setVelocity(0);
		player->setPosition(player->getPosition().x, DEFULT_START_POINT - player->getHeight()/2);

	}

	JumpAnimationPlayerState::update(player, deltaTime);

	m_timer += deltaTime;
	if (m_timer >= 15)
	{
		player->setAvoidStatus(false);
		player->setState(std::move(m_currState));

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
