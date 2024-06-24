#include "Gpower.h"
#include "Factory/ObjectFactory.h"

bool Gpower::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gpower_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gpower>(col, row));
		return lst; });

Gpower::Gpower(int col, int row)
	:Gift(Gpower_t, col, row, "Gpower")
{
}

void Gpower::open_gift()
{
}


