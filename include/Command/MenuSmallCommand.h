#pragma once
#include <SFML/Graphics.hpp>

class Menu;

class MenuSmallCommand
{
public:
	MenuSmallCommand(Menu*);
	virtual ~MenuSmallCommand() {};
	virtual void axecute() = 0;
	virtual void setPosition(sf::Vector2f);
	virtual bool contains(sf::Vector2f);
	virtual void draw(sf::RenderWindow&) const;

protected:
	sf::Sprite m_sp;
	Menu* m_menu;
};
