#include "Gpower.h"
#include "Factory/StaticObjectFactory.h"

bool Gpower::m_registered = StaticObjectFactory::registerIt(Gpower_t, [](int col, int row) -> std::unique_ptr<StaticGameObjects> { return std::make_unique<Gpower>(col, row); });


Gpower::Gpower(int col, int row)
	:Gift(Gpower_t, col, row)
{
}

void Gpower::open_gift()
{
}


