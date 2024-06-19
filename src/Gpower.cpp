#include "Gpower.h"
#include "ObjectFactory.h"

bool Gpower::m_registered = ObjectFactory::registerIt(Gpower_t, [](int col, int row) -> std::unique_ptr<Object> { return std::make_unique<Gpower>(col, row); });


Gpower::Gpower(int col, int row)
	:Gift(Gpower_t, col, row)
{
}

void Gpower::open_gift()
{
}


