#pragma once
#include <SFML/Graphics.hpp>

class MenuCommandInterface
{
public:
	MenuCommandInterface();

	virtual void axecute() = 0;
protected:
	sf::Sprite m_sp;
};
