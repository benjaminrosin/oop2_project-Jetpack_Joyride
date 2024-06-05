# pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <string>
#include <memory>
#include "Player.h"

class Controller;

class Board
{
public:
	Board();
	~Board();
	void play(Controller*, const sf::Vector2f&);
	void draw(sf::RenderWindow&)const;
	bool check_collision();
	

private:
	int m_coins = 0;
	Player m_player;
	std::list<std::unique_ptr<Object>> m_objects;

};