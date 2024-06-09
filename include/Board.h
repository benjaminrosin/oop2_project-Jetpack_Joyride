# pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <string>
#include <memory>
#include "Player.h"

const int MIN_AMOUNT = 20;

class Controller;

class Board
{
public:
	Board();
	~Board() {};
	void play(sf::RenderWindow&, float);
	void draw(sf::RenderWindow&)const;
	bool checkCollision();
	void readLevel();
	bool alive() const;
	

private:
	Player m_player;
	std::list<std::unique_ptr<Object>> m_objects;

};