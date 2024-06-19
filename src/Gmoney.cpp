#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Gmoney.h"

Gmoney::Gmoney(int col, int row)
	:Gift(Gmoney_t, col, row)
{
}

void Gmoney::open_gift()
{
}
