#include "Controller.h"
#include <iostream>
#include <string>
#include "Menu.h"
#include <fstream>
#include <sstream>
#include "Command/MuteCommand.h"
#include "Command/PauseCommand.h"
#include "Command/BackCommand.h"
#include <SFML/Audio.hpp>


int Controller::m_coins = 0;

Controller::Controller(sf::RenderWindow& wind, int best)
	: m_board(), m_wind(wind), m_bestScore(best)
{

	//reading score board from file
	m_music.openFromFile("JetpackJoyrideMusic.wav");
	m_music.setVolume(MUSIC_VOLUME);
	m_music.setLoop(true);

	resetSFMLComponents();

	m_buttons.emplace_back(std::make_unique<MuteCommand>(this, 1));
	m_buttons.emplace_back(std::make_unique<PauseCommand>(this, 2));
	m_buttons.emplace_back(std::make_unique<BackCommand>(this, 3));
	for (int i = 0; i < m_buttons.size(); i++)
	{
		auto pos = sf::Vector2f(1000 + 60 * i, 10);
		m_buttons[i]->setPosition(pos);
	}
	m_clock.restart();

	m_coins = 0;

}

std::pair<int, std::string> Controller::run() 
{
	m_music.play();

	while (m_wind.isOpen() && m_board.alive() && !m_backToMenu)
	{
		m_wind.clear(sf::Color::Black);

		m_timer += m_clock.getElapsedTime().asSeconds();
		m_delta_time = m_clock.restart().asSeconds();

		m_board.play(m_wind, m_timer, m_delta_time);

		auto curr_view = m_wind.getView();
		sf::Vector2f center = curr_view.getCenter();
		center = sf::Vector2f(m_board.getPlayerLoc().x + SCREEN_SIZE.x / 3, center.y);

		m_wind.setView(sf::View(center, curr_view.getSize()));

		moveBackground(m_delta_time);

		m_board.draw(m_wind);
		drawData();

		if (auto event = sf::Event(); m_wind.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_wind.close();
				exit(EXIT_FAILURE);
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				if (option != -1)
				{
					m_buttons[option]->axecute();
				}
			}
		}
		m_wind.display();
	}
	if (!m_board.alive())
	{
		return readNameFromUser();

	}
	return { 0, "None" };
}


void Controller::drawData()
{
	auto currView = m_wind.getView();
	m_wind.setView(m_wind.getDefaultView());

	m_data[0].setString("TIME " + std::to_string((int)m_timer));
	m_data[1].setString("COINS " + std::to_string(m_coins));
	m_data[2].setString("BEST SCORE " + std::to_string(m_bestScore));

	for (int i = 0; i < NUM_OF_DATA; i++)
	{
		m_wind.draw(m_data[i]);
	}

	for (int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i]->draw(m_wind);
	}
	m_wind.setView(currView);
}

void Controller::addToCoins(int value)
{
	m_coins += value;
}

void Controller::setVolume(int num)
{
	m_music.setVolume(num);
}

void Controller::pause()
{
	sf::RectangleShape rect;
	rect.setSize(m_wind.getView().getSize());
	rect.setFillColor(sf::Color(0, 0, 0, 125));
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	rect.setPosition(m_wind.getView().getCenter());

	m_wind.draw(rect);

	auto view = m_wind.getView();
	m_wind.setView(m_wind.getDefaultView());
	m_wind.draw(m_massege[2]);
	m_buttons[2]->draw(m_wind);
	m_wind.setView(view);

	m_wind.display();

	while (true && !m_backToMenu)
	{
		if (auto event = sf::Event(); m_wind.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_wind.close();
				exit(EXIT_FAILURE);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				break;
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				if (option != -1 && option == 2)
				{
					m_buttons[option]->axecute();
				}
			}
		}
	}
	m_clock.restart();
}

void Controller::backToManu()
{
	m_wind.setView(m_wind.getDefaultView());
	m_music.stop();
	m_backToMenu = true;
}

std::pair<int, std::string> Controller::readNameFromUser()
{
	std::string name;
	sf::Texture texture;
	texture.create(SCREEN_SIZE.x, SCREEN_SIZE.y);
	texture.update(m_wind);

	m_background[0].setTexture(texture);
	m_background[0].setColor(sf::Color(255, 255, 255, 125));

	m_wind.setView(m_wind.getDefaultView());
	m_background[0].setPosition({ 0,0 });

	auto str = m_massege[0].getString();
	str += std::to_string(m_coins);
	m_massege[0].setString(str);
	m_massege[0].setOrigin(m_massege[0].getGlobalBounds().width / 2, m_massege[0].getGlobalBounds().height / 2);

	while (m_wind.isOpen() && !m_backToMenu)
	{
		m_wind.clear(sf::Color::Black);
		m_wind.draw(m_background[0]);
		m_buttons[2]->draw(m_wind);
		for (auto& str : m_massege) {
			m_wind.draw(str);
		}

		//your score is: 
		//plaese enter your name:


		if (auto event = sf::Event(); m_wind.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_wind.close();
				exit(EXIT_FAILURE);
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				auto mousePosition = m_wind.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (m_buttons[2]->contains(mousePosition))
				{
					m_buttons[2]->axecute();
				}
			}
			else if (event.type == sf::Event::TextEntered) 
			{
				if (event.text.unicode < 128) {
					if (event.text.unicode == 8) { // Handle backspace
						if (!name.empty()) 
						{
							name.pop_back();
						}
					}
					else if (event.text.unicode == 13) { // Handle Enter key
						return { m_coins, name };
					}
					else {
						name += char(event.text.unicode);
					}
					m_massege[2].setString(name);
					m_massege[2].setOrigin(m_massege[2].getGlobalBounds().width / 2, m_massege[2].getGlobalBounds().height / 2);

				}
			}
		}
		m_wind.display();
	}

	return { m_coins ,"anonymous" };
}


int Controller::handleClick(sf::Vector2f v2f) const
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i]->contains(v2f))
		{
			return i;
		}
	}
	return -1;

	//for (int i = 0; i < NUM_OF_BUTTONS - 1; i++)
	//{
	//	if (m_buttonsGame[i].getGlobalBounds().contains(v2f))
	//	{
	//		return i;
	//	}
	//}
	//return -1;
}

void Controller::resetSFMLComponents()
{
	for (int i = 0; i < NUM_OF_DATA; i++)
	{
		m_data[i].setFillColor(sf::Color::White);
		//add outline to text
		m_data[i].setOutlineThickness(2);
		m_data[i].setOutlineColor(sf::Color::Black);
		m_data[i].setCharacterSize(30);
		m_data[i].setFont(*Resources::getInstance().getFont());
		m_data[i].setOrigin(sf::Vector2f(m_data[i].getGlobalBounds().width / 2, m_data[i].getGlobalBounds().height / 2));
		m_data[i].setPosition(sf::Vector2f(20 + 200 * i, 10));
	}
	
	for (int i = 0; i < 3; i++)
	{
		m_massege[i].setString(MASSEGE[i]);
		m_massege[i].setFillColor(sf::Color::White);
		m_massege[i].setOutlineThickness(2);
		m_massege[i].setOutlineColor(sf::Color::Black);
		m_massege[i].setCharacterSize(50);
		m_massege[i].setFont(*Resources::getInstance().getFont());
		m_massege[i].setOrigin(sf::Vector2f(m_massege[i].getGlobalBounds().width / 2, m_massege[i].getGlobalBounds().height / 2));
		m_massege[i].setPosition(sf::Vector2f(SCREEN_SIZE.x/2, 100 * (i + 2)));
	}


	m_background[0].setTexture(*Resources::getInstance().getBackground(0));
	m_background[0].setPosition(- SCREEN_SIZE.x / 6, 0);
	m_background[1].setTexture(*Resources::getInstance().getBackground(1));
	m_background[1].setPosition(m_background[0].getPosition().x +SCREEN_SIZE.x, 0);
	//m_background.setSize(SCREEN_SIZE);

	//m_boardBackground.setSize(BOARD_SIZE);
	//m_boardBackground.setPosition(sf::Vector2f(300, 0));
	//m_boardBackground.setOutlineColor(sf::Color::Black);
	//m_boardBackground.setOutlineThickness(5);
	//m_boardBackground.setFillColor(sf::Color::Color(255, 255, 255, 50));

	//for (int i = 0; i < NUM_OF_BUTTONS - 1; i++)
	//{
	//	m_buttonsGame[i].setSize(sf::Vector2f(50, 50));
	//	m_buttonsGame[i].setPosition(sf::Vector2f(1000 + 60 * i, 10));
	//	m_buttonsGame[i].setTexture(Resources::getInstance().getTextureButtons(i+1));
	//	m_buttonsGame[i].setFillColor(sf::Color::Green);
	//}
}

void Controller::moveBackground(float delta_time)
{
	int xStartOfView = m_wind.getView().getCenter().x - m_wind.getView().getSize().x / 2;
	
	for (int i = 0; i < NUM_OF_BACKGROUNDS-2; i++)
	{
		m_wind.draw(m_background[i]);

		int xEndOfBackground = m_background[i].getGlobalBounds().left + m_background[i].getGlobalBounds().width;

		if (xStartOfView >= xEndOfBackground)
		{
			m_background[i].setTexture(*Resources::getInstance().getBackground(1));
			m_background[i].move({ 2 * m_wind.getView().getSize().x, 0 });
			m_wind.draw(m_background[i]);
		}
	}

}