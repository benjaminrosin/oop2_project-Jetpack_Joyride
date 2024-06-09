#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Controller.h"

class Menu {
public:
	Menu();
	~Menu();
	void showMenu();

private:
	sf::RectangleShape m_button[NUM_OF_BUTTONS_MENU];
	sf::RectangleShape m_background;
	sf::RenderWindow m_wind;
	Controller* m_controller;


	int handleClick(sf::Vector2f) const;
	void drawButtons(sf::RenderWindow&) const;
	void newGame();
	//void loadGame();
	void showHelp();

};