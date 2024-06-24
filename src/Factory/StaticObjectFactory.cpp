//#include "Factory/StaticObjectFactory.h"
//
//std::unique_ptr<StaticGameObjects> StaticObjectFactory::create(int index)
//{
//	auto it = getMap().find(index);
//	if (it == getMap().end())
//	{
//		return nullptr;
//	}
//
//	//adding rand for position
//	//int col = std::rand() % 2;
//
//	return it->second(5,5);
//	//adding pram
//}
//std::unique_ptr<StaticGameObjects> StaticObjectFactory::create(int index, int x, int y) //for debug
//{
//	auto it = getMap().find(index);
//	if (it == getMap().end())
//	{
//		return nullptr;
//	}
//
//	return it->second(x,y);
//	//adding pram
//}
//
//bool StaticObjectFactory::registerIt(int index, std::unique_ptr<StaticGameObjects>(*fu)(int, int))
//{
//	getMap().emplace(index, fu);
//	return true;
//}
//
//StaticObjMap& StaticObjectFactory::getMap()
//{
//	static StaticObjMap map;
//	return map;
//}
