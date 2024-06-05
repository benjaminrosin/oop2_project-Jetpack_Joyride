#include "Controller.h"
#include <iostream>
#include <string>
#include "Menu.h"
#include <fstream>
#include <sstream>
#include "Utilities.h"

Controller::Controller() : m_board()
{
	resetTimer(0);
	resetSFMLComponents();
}

Controller::Controller(std::string fileName): m_board(this, fileName)
{
	resetSFMLComponents();
}

void Controller::run(sf::RenderWindow& m_wind) 
{
	while (m_wind.isOpen() && m_timer > 0 && !m_board.finished())
	{
		m_wind.clear(sf::Color::White);
		m_wind.draw(m_background);

		sf::Vector2i mousePos = sf::Mouse::getPosition(m_wind);
		sf::Vector2f mousePosF(mousePos.x, mousePos.y);

		handleHover(mousePosF, m_buttonsGame, NUM_OF_BUTTONS_BOARD);
		drawData(m_wind);

		m_wind.draw(m_boardBackground);
		
		auto delta_time = m_clock.restart();
		m_timer -= delta_time.asSeconds();

		if (m_blinking)
		{
			m_blinking = false;
			m_blockedAndPressed->glowBlockingSticks(false);
			sf::sleep(sf::seconds(0.7));
		}

		if (m_hint)
		{
			handleHint();
		}
		else if (auto event = sf::Event(); m_wind.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				m_wind.close();
				exit(EXIT_FAILURE);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				auto mousePosition = m_wind.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				
				if (m_boardBackground.getGlobalBounds().contains(mousePosition))
				{
					m_board.play(this, mousePosition);
				}
				else
				{
					int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

					switch (option)
					{
					case 0:
						hint(m_board.getAccessibleBegin(), m_board.getAccessibleEnd());
						addToScore(HINT_PRICE);
						break;

					case 1:
						saveData();
						return;
					}
				}
			}
		}
		m_board.draw(m_wind);
		m_wind.display();
	}

	if (m_board.finished() && m_score > 0)//win
	{
		printMessage(std::vector<std::string>{"YOU WON THE GAME!", "SCORE: " + std::to_string(m_score)});
	}
	else if (m_timer <= 0 || m_board.getRemainedSticks()==0 && m_score <= 0)//lose
	{
		printMessage(std::vector<std::string>{"YOU LOST THE GAME!", "SCORE: " + std::to_string(m_score)});

		
	}
}

void Controller::hint(const std::multimap<int, Stick*>::iterator& curr,
	const std::multimap<int, Stick*>::iterator& end)
{
	m_hint = true;
	m_glowingCurr = curr;
	m_glowingEnd = end;
	
	m_glowingCurr->second->glow(true);
}

void Controller::drawData(sf::RenderWindow& wind)
{
	m_data[0].setString("TIME: " + std::to_string((int)m_timer));
	m_data[1].setString("ACCESSIBLE: " + std::to_string(m_board.getAccessibleStics()));
	m_data[2].setString("REMAINED: " + std::to_string(m_board.getRemainedSticks()));
	m_data[3].setString("COLLECTED: " + std::to_string(m_board.getCollectedSticks()));
	m_data[4].setString("SCORE: " + std::to_string(m_score));

	for (int i = 0; i < NUM_OF_DATA; i++)
	{
		wind.draw(m_data[i]);
	}

	for (int i = 0; i < NUM_OF_BUTTONS_BOARD; i++)
	{
		wind.draw(m_buttonsGame[i]);
	}
}

void Controller::addToScore(int score)
{
	m_score += score;
}

void Controller::updateBlinking(Stick* obj)
{
	m_blinking = true;
	m_blockedAndPressed = obj;
}

void Controller::resetTimer(float time = 0)
{
	if (time != 0) 
	{
		m_timer = time;
	}
	else
	{
		m_timer = m_board.getRemainedSticks() * 2;
	}
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

	m_background.setTexture(Resources::getInstance().getBackground(0));
	m_background.setSize(SCREEN_SIZE);

	m_boardBackground.setSize(BOARD_SIZE);
	m_boardBackground.setPosition(sf::Vector2f(300, 0));
	m_boardBackground.setOutlineColor(sf::Color::Black);
	m_boardBackground.setOutlineThickness(5);
	m_boardBackground.setFillColor(sf::Color::Color(255, 255, 255, 50));

	for (int i = 0; i < NUM_OF_BUTTONS_BOARD; i++)
	{
		m_buttonsGame[i].setSize(sf::Vector2f(100, 100));
		m_buttonsGame[i].setPosition(sf::Vector2f(30 + i * 100, 480));
		m_buttonsGame[i].setTexture(Resources::getInstance().getTextureBoardButtons(i));
	}
}

void Controller::handleHint()
{
	sf::sleep(sf::seconds(0.7));
	(*m_glowingCurr).second->glow(false);
	++m_glowingCurr;
	if (m_glowingCurr == m_glowingEnd)
	{
		m_hint = false;
		return;
	}
	(*m_glowingCurr).second->glow(true);
}

void Controller::saveData() const
{
	auto file = std::ofstream(FILE_NAME);

	file.clear();
	
	file << m_score << " " << int(m_timer) << " " << m_board.getCollectedSticks() <<'\n';
	
	m_board.writeSticks(file);
}

