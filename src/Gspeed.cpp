#include "Gspeed.h"
#include "ObjectFactory.h"

bool Gspeed::m_registered = ObjectFactory::registerIt(Gspeed_t, [](int col, int row) -> std::unique_ptr<Object> { return std::make_unique<Gspeed>(col, row); });

Gspeed::Gspeed(int col, int row)
	:Gift(Gspeed_t, col, row)
{
}

void Gspeed::open_gift()
{
}

