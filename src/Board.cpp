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
	//if (auto event = sf::Event(); wind.pollEvent(event))
	//{
	//	/*if (event.type == sf::Event::KeyPressed &&
	//		event.key.code == sf::Keyboard::Space)
	//	{*/
	//	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//	{
	//		//flyyyyyyyyyy
	//		m_player->jump();
	//		m_player->update(delta_time);
	//	}
	//}

	if (auto event = sf::Event(); wind.pollEvent(event))
	{
		if (event.type == sf::Event::KeyReleased &&
			event.key.code == sf::Keyboard::Space)
		{
			m_player->handleSpaceRelease(); // טיפול במקש הרווח שנשחרר
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_player->jump();
		m_player->update(delta_time);
	}

	m_player->update(delta_time);
	m_player->move_and_change_sprite(timer, m_player.get());

	//cheack collision
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
			m_objects.push_back(ObjectFactory::create(c));
		}
		row++;
	}
}

bool Board::alive() const
{
	return true;
}

//void Board::moveBackground(float delta_time, sf::RenderWindow& wind) //נסיון. צריך לשנות
//{
//	// קבלת הטקסטורה של הרקע
//	m_background = Resources::getInstance().getBackground(1);
//	sf::Vector2u backgroundSize = m_background->getSize();
//	sf::Sprite sprite;
//	sprite.setTexture(*m_background);
//	float scrollSpeed = 200.f;
//
//	// חישוב ההזזה האופקית בהתבסס על מהירות הגלילה והזמן שעבר
//	static float offsetX = 0.f;
//	offsetX += scrollSpeed * delta_time;
//
//	// אם ההזזה עוברת את רוחב הרקע, לאתחל אותה
//	if (offsetX >= backgroundSize.x)
//		offsetX -= backgroundSize.x;
//
//	// צייר את הרקע המגלול
//	for (float i = -offsetX; i < wind.getSize().x; i += backgroundSize.x)
//	{
//		for (unsigned int j = 0; j < wind.getSize().y; j += backgroundSize.y)
//		{
//			sprite.setPosition(i, j);
//			wind.draw(sprite);
//		}
//	}
//}

