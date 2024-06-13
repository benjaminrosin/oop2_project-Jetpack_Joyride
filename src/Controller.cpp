#include "Controller.h"
#include <iostream>
#include <string>
#include "Menu.h"
#include <fstream>
#include <sstream>
//#include "Utilities.h"

Controller::Controller() : m_board()
{
	m_clock.restart();
	resetSFMLComponents();
}


void Controller::run(sf::RenderWindow& m_wind) 
{
	while (m_wind.isOpen() && m_board.alive())
	{
		m_wind.clear(sf::Color::White);
		//m_wind.draw(m_background);		
		m_timer = m_clock.getElapsedTime().asSeconds();

		drawData(m_wind);
		
		if (auto event = sf::Event(); m_wind.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				m_wind.close();
				exit(EXIT_FAILURE);
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				//bottons
				//auto mousePosition = m_wind.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				//
				//if (m_boardBackground.getGlobalBounds().contains(mousePosition))
				//{
				//	m_board.play(this, mousePosition);
				//}
				//else
				//{
				//	int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

				//	switch (option)
				//	{
				//	case 0:
				//		hint(m_board.getAccessibleBegin(), m_board.getAccessibleEnd());
				//		addToScore(HINT_PRICE);
				//		break;

				//	case 1:
				//		saveData();
				//		return;
				//	}
				//}
			}
		}
		m_delta_time = m_clock.restart().asSeconds();

		m_board.play(m_wind, m_timer, m_delta_time);

		//change view
		auto curr_view = m_wind.getView();
		sf::Vector2f size = curr_view.getSize();
		sf::Vector2f center = curr_view.getCenter();
		center = sf::Vector2f(center.x, center.y);

		m_wind.setView(sf::View(center, size));

		moveBackground(m_delta_time, m_wind);
		//m_wind.setView(sf::View(sf::FloatRect(m_background.getPosition(), sf::Vector2f(m_background.getTexture()->getSize()))));

		m_board.draw(m_wind);

		m_wind.display();
	}
}


void Controller::drawData(sf::RenderWindow& wind)
{
	m_data[0].setString("TIME: " + std::to_string((int)m_timer));
	//m_data[1].setString("ACCESSIBLE: " + std::to_string(m_board.getAccessibleStics()));
	//m_data[2].setString("REMAINED: " + std::to_string(m_board.getRemainedSticks()));
	//m_data[3].setString("COLLECTED: " + std::to_string(m_board.getCollectedSticks()));
	m_data[4].setString("COINS: " + std::to_string(m_coins));

	for (int i = 0; i < NUM_OF_DATA; i++)
	{
		wind.draw(m_data[i]);
	}

	for (int i = 0; i < NUM_OF_BUTTONS_BOARD; i++)
	{
		wind.draw(m_buttonsGame[i]);
	}
}

void Controller::addToCoins(int coins)
{
	m_coins += coins;
}

int Controller::handleClick(sf::Vector2f v2f) const
{
	for (int i = 0; i < NUM_OF_BUTTONS_MENU; i++)
	{
		if (m_buttonsGame[i].getGlobalBounds().contains(v2f))
		{
			return i;
		}
	}
	return -1;
}

void Controller::resetSFMLComponents()
{
	for (int i = 0; i < NUM_OF_DATA; i++)
	{
		m_data[i].setFillColor(sf::Color::White);
		m_data[i].setCharacterSize(40);
		m_data[i].setFont(*Resources::getInstance().getFont());
		m_data[i].setOrigin(sf::Vector2f(m_data[i].getGlobalBounds().width / 2, m_data[i].getGlobalBounds().height / 2));
		m_data[i].setPosition(sf::Vector2f(10, 20 + 100 * i));
	}

	m_background.setTexture(*Resources::getInstance().getBackground(0));
	//m_background.setSize(SCREEN_SIZE);

	//m_boardBackground.setSize(BOARD_SIZE);
	//m_boardBackground.setPosition(sf::Vector2f(300, 0));
	//m_boardBackground.setOutlineColor(sf::Color::Black);
	//m_boardBackground.setOutlineThickness(5);
	//m_boardBackground.setFillColor(sf::Color::Color(255, 255, 255, 50));

	for (int i = 0; i < NUM_OF_BUTTONS_BOARD; i++)
	{
		m_buttonsGame[i].setSize(sf::Vector2f(100, 100));
		m_buttonsGame[i].setPosition(sf::Vector2f(30 + i * 100, 480));
		m_buttonsGame[i].setTexture(Resources::getInstance().getTextureBoardButtons(i));
	}
}

void Controller::moveBackground(float delta_time, sf::RenderWindow& wind) //נסיון. צריך לשנות
{
	// קבלת הטקסטורה של הרקע
	m_background.setTexture(*Resources::getInstance().getBackground(1));
	float scrollSpeed = 200.f;

	// חישוב ההזזה האופקית בהתבסס על מהירות הגלילה והזמן שעבר
	static float offsetX = 0.f;
	offsetX += scrollSpeed * delta_time;

	// אם ההזזה עוברת את רוחב הרקע, לאתחל אותה
	if (offsetX >= SCREEN_SIZE.x)
		offsetX -= SCREEN_SIZE.x;

	// צייר את הרקע המגלול
	for (float i = -offsetX; i < wind.getSize().x; i += SCREEN_SIZE.x)
	{
		for (unsigned int j = 0; j < wind.getSize().y; j += SCREEN_SIZE.y)
		{
			m_background.setPosition(i, j);
			wind.draw(m_background);
		}
	}
}