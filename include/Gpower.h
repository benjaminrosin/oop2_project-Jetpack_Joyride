#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gpower :public Gift
{
public:
	Gpower(int, int);

private:
	static bool m_registered;
};
