#include "Board.h"
#include "JumpAnimationPlayerState.h"
#include "WalkAnimationPlayerState.h"
#include <iostream>
#include <fstream>
#include <memory>
#include "ObjectFactory.h"

Board::Board()
{
	m_objects.clear();
	readLevel();
	readLevel();
	m_player = std::make_unique<Player>();
	//m_player->setState(std::make_unique<WalkAnimationPlayerState>());

}

void Board::play(sf::RenderWindow& wind, float timer, float delta_time)//לשים לב שיש גם טיימר וגם דלתא
{
	if (auto event = sf::Event(); wind.pollEvent(event))
	{
		if (event.type == sf::Event::KeyReleased &&
			event.key.code == sf::Keyboard::Space)
		{
			m_player->handleSpaceRelease(); // טיפול במקש הרווח שנשחרר
		}
	}

	//לבדוק
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_player->jump();
	}

	m_player->update(delta_time);

	//check collision

	std::for_each(m_objects.begin(), m_objects.end(), [&](auto &obj) {if (obj!=nullptr) obj->move_and_change_sprite(delta_time, &(*m_player)); });


	//moveBackground(delta_time, wind);
	if (m_objects.size() < MIN_AMOUNT)
	{
		readLevel();
	}
}

void Board::draw(sf::RenderWindow& wind) const
{
	wind.draw(m_player->getDrawable());
	std::for_each(m_objects.begin(), m_objects.end(), [&wind](auto &obj) {if (obj != nullptr) wind.draw(obj->getDrawable()); });

}

bool Board::checkCollision()
{
	return false;
}

void Board::readLevel()
{
	//for now the func will read level from txt file, hopfully 
	//the game will ganarate its levels
	char c;
	auto file = std::ifstream("level.txt");
	int col = 0;
	int row = 0;

	while (file.get(c))
	{
		if (c == '\n')
		{
			row = 0;
			col++;
			continue;
		}

		else if (c != '-')
		{
			auto temp = ObjectFactory::create(c);
			if (temp != nullptr) {
				//m_objects.push_back(std::move(temp));
			}
			
		}
		row++;
	}
}

bool Board::alive() const
{
	return true;
}

sf::Vector2f Board::getPlayerLoc() const
{
	return m_player->getDrawable().getPosition();
}

