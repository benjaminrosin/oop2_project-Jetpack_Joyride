#include "Gspeed.h"
#include "Factory/StaticObjectFactory.h"

bool Gspeed::m_registered = StaticObjectFactory::registerIt(Gspeed_t, [](int col, int row) -> std::unique_ptr<StaticGameObjects> { return std::make_unique<Gspeed>(col, row); });

Gspeed::Gspeed(int col, int row)
	:Gift(Gspeed_t, col, row)
{
}

void Gspeed::open_gift()
{
}

