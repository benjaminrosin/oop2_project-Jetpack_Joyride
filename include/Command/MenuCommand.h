#pragma once
#include <SFML/Graphics.hpp>

class Menu;

class MenuCommand
{
public:
	MenuCommand(Menu*, std::string);

	virtual void axecute() = 0;
	//void setSptire(sf::Vector2f, int);
	void setPosition(sf::Vector2f);
	bool contains(sf::Vector2f);
	void draw(sf::RenderWindow&) const;
protected:
	sf::Sprite m_sp;
	sf::Text m_name;
	Menu* m_menu;
};
