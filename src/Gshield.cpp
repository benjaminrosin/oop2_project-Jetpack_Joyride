#include "Gshield.h"
#include "Factory/ObjectFactory.h"

bool Gshield::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gshield_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gshield>(col, row));
		return lst; });

Gshield::Gshield(int col, int row)
	:Gift(Gshield_t, col, row, "Gshield")
{
}

void Gshield::open_gift()
{
}
