#include "Gpower.h"
#include "Factory/ObjectFactory.h"
#include "Utilities.h"

bool Gpower::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gpower_t,
	[](int col) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Gpower>(col, randomY()));
		return lst; });

Gpower::Gpower(int col, int row)
	:Gift(Gpower_t, col, row, "Gpower")
{
}




