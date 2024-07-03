#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Controller.h"
#include "Command/MenuCommand.h"
#include <vector>

class Menu {
public:
	Menu();
	~Menu();
	void showMenu();
	void newGame();
	void highScore();
	void showHelp();
	void backToMenu();
	
private:
	//sf::RectangleShape m_button[NUM_OF_BUTTONS_MENU];
	sf::RectangleShape m_background;
	sf::RenderWindow m_wind;
	std::unique_ptr <Controller> m_controller; 
	std::vector<std::unique_ptr<MenuCommand>> m_buttons;
	std::vector<std::unique_ptr<MenuCommand>> m_smallButtons;
	sf::Sprite m_logo;
	sf::Sprite m_scoreBoardSign;
	sf::Text m_text;
	std::multimap<int, std::string, std::greater<int>> m_scoreBoard;
	bool m_backToMenu = false;
	int handleClick(std::vector<std::unique_ptr<MenuCommand>>&, sf::Vector2f) const;
	//void drawButtons(sf::RenderWindow&) const;


};