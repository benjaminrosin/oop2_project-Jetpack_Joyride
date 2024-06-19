#include "Menu.h"
#include <iostream>
#include <exception>
#include "Resources.h"
#include "Command/StartGameCommand.h"
#include "Command/RulesCommand.h"
#include "Command/HighScoreCommand.h"

Menu::Menu()
{
	m_background.setTexture(Resources::getInstance().getBackground(0));
	m_background.setSize(SCREEN_SIZE);
	m_controller = nullptr;

	m_buttons.emplace_back(std::make_unique<StartGameCommand>(this));
	m_buttons.emplace_back(std::make_unique<HighScoreCommand>(this));
	m_buttons.emplace_back(std::make_unique<RulesCommand>(this));
	//exit button?

	for (int i = 0; i < m_buttons.size(); i++)
	{
		auto pos = sf::Vector2f(2 * SCREEN_SIZE.x / 3, 200 * (i + 1));
		m_buttons[i]->setSptire(pos, i);
	}

}

Menu::~Menu()
{
	if (m_controller)
	{
		delete m_controller;
	}
}

void Menu::showMenu()
{

	m_wind.create(sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Jetpack Joyride");
	m_wind.setFramerateLimit(60);

	while (m_wind.isOpen())
	{
		m_wind.clear(sf::Color::White);
		m_wind.draw(m_background);

		//sf::Vector2i mousePos = sf::Mouse::getPosition(m_wind);
		//sf::Vector2f mousePosF(mousePos.x, mousePos.y);

		//handleHover(mousePosF, m_button, NUM_OF_BUTTONS_MENU);
		std::for_each(m_buttons.begin(), m_buttons.end(), [&](auto& but) {but->draw(m_wind); });

		m_wind.display();

		//hover effect

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

				if (option == -1) {
					//m_wind.close();
				}
				else {
					m_buttons[option]->axecute();
				}
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
	m_controller = new Controller();
	m_controller->run(m_wind);
	delete m_controller;
	m_controller = nullptr;
}

void Menu::highScore()
{
	std::cout << "high score\n";
}

void Menu::showHelp()
{
	m_wind.clear(sf::Color::White);

	m_wind.clear();
	m_background.setTexture(Resources::getInstance().getBackground(2));

	m_wind.draw(m_background);
	
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
				return;
			}
		}
	}
}
