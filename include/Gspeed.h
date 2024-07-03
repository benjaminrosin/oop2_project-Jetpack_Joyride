#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gspeed :public Gift
{
public:
	Gspeed(int, int);
	
private:
	static bool m_registered;


};
