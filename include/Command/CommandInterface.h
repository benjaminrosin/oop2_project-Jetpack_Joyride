#pragma once
#include <SFML/Graphics.hpp>

class Menu;

class CommandInterface
{
public:
	CommandInterface(Menu*);

	virtual void axecute() = 0;
	void setSptire(sf::Vector2f, int);
	bool contains(sf::Vector2f);
	void draw(sf::RenderWindow&) const;
protected:
	sf::Sprite m_sp;
	Menu* m_menu;
};
