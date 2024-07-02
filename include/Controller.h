# pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Command/BoardCommand.h"
#include "Board.h"
#include <string>
#include "Resources.h"
#include <string>


class Controller {
public:
	Controller(sf::RenderWindow&, int);
	std::pair<int, std::string> run();
	static void addToCoins(int = 1);
	void setVolume(int);
	void pause();
	void backToManu();
	//void back();
	std::pair<int, std::string> readNameFromUser();

private:
	Board m_board;
	sf::Text m_data[NUM_OF_DATA];
	sf::Sprite m_background[2];
	sf::Text m_massege[3];
	int m_bestScore = 0;

	std::vector<std::unique_ptr<BoardCommand>> m_buttons;
	sf::RenderWindow& m_wind;
	sf::Music m_music;

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

