# pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <string>
#include <memory>
#include "Player.h"
#include "StaticGameObjects.h"
#include "MovingGameObjects.h"

class Controller;

class Board
{
public:
	Board();
	~Board() {};
	void play(sf::RenderWindow&, float);
	void draw(sf::RenderWindow&)const;
	void generateLevel(sf::RenderWindow&, float);
	bool alive() const;
	sf::Vector2f getPlayerLoc() const;

private:
	std::unique_ptr<Player> m_player;
	std::list<std::unique_ptr<StaticGameObjects>> m_statics;
	std::list<std::unique_ptr<MovingGameObjects>> m_movings;
	float m_objTimer = 1;

	bool collide(Object&);

};