#include "Gshield.h"
#include "ObjectFactory.h"

bool Gshield::m_registered = ObjectFactory::registerIt(Gshield_t, [](int col, int row) -> std::unique_ptr<Object> { return std::make_unique<Gshield>(col, row); });


Gshield::Gshield(int col, int row)
	:Gift(Gshield_t, col, row)
{
}

void Gshield::open_gift()
{
}
