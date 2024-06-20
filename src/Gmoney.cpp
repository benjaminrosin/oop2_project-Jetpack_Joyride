#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Gmoney.h"
#include "Factory/StaticObjectFactory.h"

bool Gmoney::m_registered = StaticObjectFactory::registerIt(Gmoney_t, [](int col, int row) -> std::unique_ptr<StaticGameObjects> { return std::make_unique<Gmoney>(col, row); });


Gmoney::Gmoney(int col, int row)
	:Gift(Gmoney_t, col, row)
{
}

void Gmoney::open_gift()
{
}
