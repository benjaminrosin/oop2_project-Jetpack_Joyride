#pragma once
#include <SFML/Graphics.hpp>
#include "StaticGameObjects.h"

class Player;

class Coin:public StaticGameObjects {
public:
	Coin(int, int);

private:
	static bool m_registered;

};