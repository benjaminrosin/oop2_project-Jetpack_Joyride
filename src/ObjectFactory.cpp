#include "ObjectFactory.h"

std::unique_ptr<Object> ObjectFactory::create(int index)
{
	auto it = getMap().find(index);
	if (it == getMap().end)
	{
		return nullptr;
	}
	return it->second();//adding pram
}

bool ObjectFactory::registerIt(int index, std::unique_ptr<Object>(*fu)()))
{
	getMap().emplace(index, fu);
	return true;
}

objMap& ObjectFactory::getMap()
{
	static objMap map;
	return map;
}
