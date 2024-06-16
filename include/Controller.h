# pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <string>
#include "Resources.h"

class Controller {
public:
	Controller();
	void run(sf::RenderWindow&);
	
private:
	Board m_board;
	sf::Text m_data[NUM_OF_DATA];
	 sf::Sprite m_background;
	sf::RectangleShape m_buttonsGame[NUM_OF_BUTTONS_BOARD];

	sf::Clock m_clock;
	float m_timer;
	float m_delta_time;
	int m_coins = 0;

	void drawData(sf::RenderWindow&);
	void addToCoins(int);
	int handleClick(sf::Vector2f) const;
	void resetSFMLComponents();
	void moveBackground(float ,sf::RenderWindow&);

};

