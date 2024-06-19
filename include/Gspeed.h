#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gspeed :public Gift
{
public:
	Gspeed(int, int);
	
	virtual void open_gift();
private:
	static bool m_registered;


};
