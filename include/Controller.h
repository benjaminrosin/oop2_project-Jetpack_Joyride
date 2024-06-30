# pragma once
#include <SFML/Graphics.hpp>
#include "Command/BoardCommand.h"
#include "Board.h"
#include <string>
#include "Resources.h"

class Controller {
public:
	Controller(sf::RenderWindow&);
	void run();
	static void addToCoins(int = 1);
	void setVolume(int);
	void pause();
	void backToManu();
	//void back();
	
private:
	Board m_board;
	sf::Text m_data[NUM_OF_DATA];
	sf::Sprite m_background[2];
	//sf::RectangleShape m_buttonsGame[NUM_OF_BUTTONS -1];
	std::vector<std::unique_ptr<BoardCommand>> m_buttons;
	sf::RenderWindow& m_wind;

	//sf::Music m_music;

	sf::Clock m_clock;
	float m_timer;
	float m_delta_time;
	static int m_coins;
	bool m_backToMenu = false;

	void drawData();

	int handleClick(sf::Vector2f) const;
	void resetSFMLComponents();
	void moveBackground(float);

};

