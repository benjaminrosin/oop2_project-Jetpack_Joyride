#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gmoney :public Gift
{
public:
	Gmoney(int, int);
	
	virtual void open_gift();
private:

};
