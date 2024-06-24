#include "Gspeed.h"
#include "Factory/ObjectFactory.h"

bool Gspeed::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gspeed_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gspeed>(col, row));
		return lst; });

Gspeed::Gspeed(int col, int row)
	:Gift(Gspeed_t, col, row, "Gspeed")
{
}

void Gspeed::open_gift()
{
}

