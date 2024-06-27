#pragma once
#include <SFML/Graphics.hpp>

class Controller;

class BoardCommand
{
public:
	BoardCommand(Controller*, int);
	virtual ~BoardCommand() {};
	virtual void axecute() = 0;
	virtual void setPosition(sf::Vector2f);
	virtual bool contains(sf::Vector2f);
	virtual void draw(sf::RenderWindow&);

protected:
	sf::Sprite m_sp;
	Controller* m_controller;
};
