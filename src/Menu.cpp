#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include "Resources.h"
#include "Command/StartGameCommand.h"
#include "Command/RulesCommand.h"
#include "Command/HighScoreCommand.h"
#include "Command/BackCommandMenu.h"

Menu::Menu()
{
	m_background.setTexture(Resources::getInstance().getBackground(0));
	m_background.setSize(SCREEN_SIZE);

	m_logo.setTexture(*Resources::getInstance().getBackground(3));
	m_logo.setOrigin(m_logo.getGlobalBounds().width / 2, m_logo.getGlobalBounds().height / 2);
	m_logo.setPosition(400, SCREEN_SIZE.y/2);

	m_controller = nullptr;

	m_buttons.emplace_back(std::make_unique<StartGameCommand>(this, "play"));
	m_buttons.emplace_back(std::make_unique<HighScoreCommand>(this, "score board"));
	m_buttons.emplace_back(std::make_unique<RulesCommand>(this, "rules"));
	m_buttons.emplace_back(std::make_unique<BackCommandMenu>(this, " "));
	//exit button?
	

	for (int i = 0; i < m_buttons.size()-1; i++)
	{
		auto pos = sf::Vector2f(0.75 * SCREEN_SIZE.x, SCREEN_SIZE.y / m_buttons.size() + 150 * i);
		m_buttons[i]->setPosition(pos);
	}

	auto file = std::ifstream("Score board.txt");

	if (!file.is_open())
	{
		throw std::runtime_error("couldn't load score file");
	}

	std::string line;
	int score;

	for (int i = 0; i < 3; i++){
		std::getline(file, line);
		std::istringstream iss(line);
		if ((iss >> score))
		{
			std::getline(iss, line);
			m_scoreBoard.emplace(score, line);
		}
		else
		{
			//throw std::runtime_error("format isn't seported");
		}
	}

	m_scoreBoardSign.setTexture(*Resources::getInstance().getTextureButtons(0));
	m_scoreBoardSign.setOrigin(sf::Vector2f(m_scoreBoardSign.getGlobalBounds().width / 2, m_scoreBoardSign.getGlobalBounds().height / 2));
	m_scoreBoardSign.setScale(sf::Vector2f(2, 1));
	
	m_text.setCharacterSize(30);
	m_text.setFont(*Resources::getInstance().getFont());
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(2);
	
}

Menu::~Menu()
{
	/*if (m_controller)
	{
		delete m_controller;
	}*/

	auto file = std::ofstream("Score board.txt", std::ios_base::trunc);

	if (!file.is_open())
	{
		throw std::runtime_error("couldn't load score file");
	}

	auto score = m_scoreBoard.begin();

	for (int i = 0; i < 3; i++)
	{
		file << score->first << " " << score->second << '\n';
		score++;
	}
}

void Menu::showMenu()
{
	if (m_firstRun) {
		m_wind.create(sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Jetpack Joyride");
		m_wind.setFramerateLimit(60);
		m_firstRun = false;
	}
	

	while (m_wind.isOpen())
	{
		m_wind.setView(m_wind.getDefaultView());
		m_wind.clear(sf::Color::White);
		m_wind.draw(m_background);
		m_wind.draw(m_logo);
		//sf::Vector2i mousePos = sf::Mouse::getPosition(m_wind);
		//sf::Vector2f mousePosF(mousePos.x, mousePos.y);

		//handleHover(mousePosF, m_button, NUM_OF_BUTTONS_MENU);
		std::for_each(m_buttons.begin(), m_buttons.end() - 1, [&](auto& but) {but->draw(m_wind); });

		m_wind.display();


		if (auto event = sf::Event(); m_wind.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_wind.close();
				break;

			case sf::Event::MouseButtonReleased:
			{
				int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

				if (option != -1) {
					m_buttons[option]->axecute();
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				for (auto& buttun : m_buttons)
				{
					buttun->contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
				}
				break;
			}
				
			}
		}

	}
}

int Menu::handleClick(sf::Vector2f v2f) const
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i]->contains(v2f))
		{
			return i;
		}
	}
	return -1;
}

void Menu::newGame()
{
	//m_controller = new Controller(m_wind);
	m_controller = std::make_unique<Controller>(m_wind, m_scoreBoard.begin()->first);
	m_scoreBoard.emplace(m_controller->run());
	//auto ret = m_controller->run();
	//std::cout << ret.first << " " << ret.second << "\n";
	//delete m_controller;
	//m_controller = nullptr;
}

void Menu::highScore()
{
	std::cout << "high score\n";
	m_wind.clear();
	m_wind.draw(m_background);

	auto pos = sf::Vector2f(SCREEN_SIZE.x / 2, 200);
	m_text.setCharacterSize(60);
	m_text.setString("score board");
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	m_text.setPosition(pos);
	m_buttons[3]->draw(m_wind);
	m_wind.draw(m_text);

	m_text.setCharacterSize(40);
	auto score = m_scoreBoard.begin();

	for (int i = 0; i < 3; i++)
	{
		pos.y += m_scoreBoardSign.getGlobalBounds().height;
		m_scoreBoardSign.setPosition(pos);
		m_wind.draw(m_scoreBoardSign);
		m_text.setString(std::to_string(score->first) + ' ' + score->second);
		m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
		m_text.setPosition(m_scoreBoardSign.getPosition());
		m_wind.draw(m_text);
		score++;
	}

	m_wind.display();

	while (true)
	{
		if (auto event = sf::Event(); m_wind.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_wind.close();
				return;
			case sf::Event::MouseButtonReleased:
				int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

				if (option != -1 && option == 3) {
					m_buttons[option]->axecute();
				}
				break;
			}
		}
	}
}

void Menu::showHelp()
{
	m_wind.clear(sf::Color::White);

	m_wind.clear();
	m_background.setTexture(Resources::getInstance().getBackground(2));

	m_wind.draw(m_background);
	m_buttons[3]->draw(m_wind);

	m_background.setTexture(Resources::getInstance().getBackground(0));
	m_wind.display();

	while (true)
	{
		if (auto event = sf::Event(); m_wind.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_wind.close();
				return;
			case sf::Event::MouseButtonReleased:
				int option = handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

				if (option != -1 && option == 3) {
					m_buttons[option]->axecute();
				}
				break;;
			}
		}
	}
}
