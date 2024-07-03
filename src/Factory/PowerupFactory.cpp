#include "Factory/PowerupFactory.h"

std::unique_ptr<PlayerAnimationState> PowerupFactory::create(int index, Player* p)
{
	auto it = getMap().find(index);
	if (it == getMap().end())
	{
		throw std::runtime_error("The requested object was not found");
	}
	return it->second(p);
}

bool PowerupFactory::registerIt(int index, Func fu)
{
	getMap().emplace(index, fu);
	return true;
}

ObjMap& PowerupFactory::getMap()
{
	static ObjMap map;
	return map;
}

