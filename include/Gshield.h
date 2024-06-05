#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gshield :public Gift
{
public:
	Gshield(int, int);
	
	virtual void open_gift();
private:

};
