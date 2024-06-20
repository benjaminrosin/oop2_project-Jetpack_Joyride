#include "Gshield.h"
#include "Factory/StaticObjectFactory.h"

bool Gshield::m_registered = StaticObjectFactory::registerIt(Gshield_t, [](int col, int row) -> std::unique_ptr<StaticGameObjects> { return std::make_unique<Gshield>(col, row); });


Gshield::Gshield(int col, int row)
	:Gift(Gshield_t, col, row)
{
}

void Gshield::open_gift()
{
}
