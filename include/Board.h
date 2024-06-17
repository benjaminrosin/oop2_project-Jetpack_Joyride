# pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <string>
#include <memory>
#include "Player.h"

const int MIN_AMOUNT = 5;

class Controller;

class Board
{
public:
	Board();
	~Board() {};
	void play(sf::RenderWindow&, float, float);
	void draw(sf::RenderWindow&)const;
	bool checkCollision();
	void readLevel(sf::RenderWindow&);
	bool alive() const;
	sf::Vector2f getPlayerLoc() const;
	//void moveBackground(float, sf::RenderWindow&);


private:
	std::unique_ptr<Player> m_player;
	std::list<std::unique_ptr<Object>> m_objects;
	const sf::Texture* m_background;
};