#include "Factory/MovingObjectFactory.h"

std::unique_ptr<MovingGameObjects> MovingObjectFactory::create(int index)
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
std::unique_ptr<MovingGameObjects> MovingObjectFactory::create(int index, int x, int y) //for debug
{
	auto it = getMap().find(index);
	if (it == getMap().end())
	{
		return nullptr;
	}

	return it->second(x,y);
	//adding pram
}

bool MovingObjectFactory::registerIt(int index, std::unique_ptr<MovingGameObjects>(*fu)(int, int))
{
	getMap().emplace(index, fu);
	return true;
}

MovingObjMap& MovingObjectFactory::getMap()
{
	static MovingObjMap map;
	return map;
}
