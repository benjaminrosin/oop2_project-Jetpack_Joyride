#include "Objects/Gspeed.h"
#include "Factory/ObjectFactory.h"
#include "Utilities.h"

bool Gspeed::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gspeed_t,
	[](int col) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gspeed>(col, randomY()));
		return lst; });

Gspeed::Gspeed(int col, int row)
	:Gift(Gspeed_t, col, row, "Gspeed")
{}


