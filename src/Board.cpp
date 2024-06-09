#include "Board.h"

Board::Board()
{
	m_objects.clear();
	readLevel();
	readLevel();
}

void Board::play(sf::RenderWindow& wind, float dalta_time)
{
	if (auto event = sf::Event(); wind.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Space)
		{
			//flyyyyyyyyyy
		}
		else
		{
			//walk
		}
	}

	//cheack collision
	std::for_each(m_objects.begin(), m_objects.end(), [&](auto &obj) {obj->move_and_change_sprite(dalta_time, &m_player); });

	if (m_objects.size() < MIN_AMOUNT)
	{
		readLevel();
	}
}

void Board::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_player.getDrawable());
	std::for_each(m_objects.begin(), m_objects.end(), [&wind](auto &obj) {wind.draw(obj->getDrawable()); });

}

bool Board::checkCollision()
{
	return false;
}

void Board::readLevel()
{
}

bool Board::alive() const
{
	return true;
}

