#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gpower :public Gift
{
public:
	Gpower(int, int);

	virtual void open_gift();
private:
	static bool m_registered;


};
