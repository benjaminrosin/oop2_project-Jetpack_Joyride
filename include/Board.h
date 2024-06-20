# pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <string>
#include <memory>
#include "Player.h"
#include "StaticGameObjects.h"
#include "MovingGameObjects.h"

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
	//void findCollision(std::list<std::unique_ptr<Object>>&);
	bool collide(Object&);
private:
	//void deleteObjects(sf::RenderWindow&);

	std::unique_ptr<Player> m_player;
	//std::list<std::unique_ptr<Object>> m_statics;
	std::list<std::unique_ptr<StaticGameObjects>> m_statics;
	//std::list<std::unique_ptr<Object>> m_movings;
	std::list<std::unique_ptr<MovingGameObjects>> m_movings;
	//const sf::Texture* m_background;
	float m_objTimer = 1;
};