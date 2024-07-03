#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gmoney :public Gift
{
public:
	Gmoney(int, int);
	virtual void draw(sf::RenderWindow&)const override;
	int getValue() const;
	
private:
	static bool m_registered;
	sf::Text m_text;
	int m_value;


};
