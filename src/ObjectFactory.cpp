#include "ObjectFactory.h"

std::unique_ptr<Object> ObjectFactory::create(int index)
{
	auto it = getMap().find(index);
	if (it == getMap().end())
	{
		return nullptr;
	}

	//adding rand for position
	//int col = std::rand() % 2;

	return it->second(5,5);
	//adding pram
}

bool ObjectFactory::registerIt(int index, std::unique_ptr<Object>(*fu)(int, int))
{
	getMap().emplace(index, fu);
	return true;
}

objMap& ObjectFactory::getMap()
{
	static objMap map;
	return map;
}
