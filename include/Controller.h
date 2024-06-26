# pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <string>
#include "Resources.h"

class Controller {
public:
	Controller();
	void run(sf::RenderWindow&);
	static void addToCoins();
	
private:
	Board m_board;
	sf::Text m_data[NUM_OF_DATA];
	sf::Sprite m_background[2];
	sf::RectangleShape m_buttonsGame[NUM_OF_BUTTONS -1];

	sf::Clock m_clock;
	float m_timer;
	float m_delta_time;
	static int m_coins;

	void drawData(sf::RenderWindow&);

	int handleClick(sf::Vector2f) const;
	void resetSFMLComponents();
	void moveBackground(float ,sf::RenderWindow&);

};

