#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Gmoney.h"
#include "Factory/ObjectFactory.h"

bool Gmoney::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gmoney_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gmoney>(col, row));
		return lst; });


Gmoney::Gmoney(int col, int row)
	:Gift(Gmoney_t, col, row, "Gmoney")
{
}

void Gmoney::open_gift()
{
}
