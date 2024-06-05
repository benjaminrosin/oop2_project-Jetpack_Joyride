# pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <string>
#include "Resources.h"

class Controller {
public:
	Controller();
	Controller(std::string);
	void run(sf::RenderWindow&);
	
private:
	Board m_board;
	sf::Text m_data[NUM_OF_DATA];
	sf::RectangleShape m_background;
	sf::RectangleShape m_buttonsGame[NUM_OF_BUTTONS_BOARD];

	sf::Clock m_clock;

	void drawData(sf::RenderWindow&);
	int handleClick(sf::Vector2f) const;
	void resetSFMLComponents();

};

