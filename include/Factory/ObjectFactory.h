#pragma once
#include "Objects/MovingGameObjects.h"
#include "Objects/StaticGameObjects.h"
#include <memory>
#include <map>
#include <list>
#include <functional>

class Player;

template <typename T>
class ObjectFactory
{
public:
	typedef std::function<std::list<std::unique_ptr<T>>(int, Player*)> func2;
	typedef std::function<std::list<std::unique_ptr<T>>(int)> func1;
	typedef std::map<int, func2> ObjMap;

	static std::list<std::unique_ptr<T>>  create(int, int, Player*); 

	static bool registerIt(int, func1);
	static bool registerIt(int, func2);

	static int getSize() { return getMap().size(); };

private:
	static ObjMap& getMap();
};

template <typename T>
std::list<std::unique_ptr<T>> ObjectFactory<T>::create(int index, int x, Player* p)
{
	auto it = getMap().find(index);
	if (it == getMap().end())
	{
		throw std::runtime_error("The requested object was not found");
	}
	return it->second(x,p);
}

template <typename T>
bool ObjectFactory<T>::registerIt(int index, func1 fu)
// overloading for functions that requires only one arg to craete
{
	getMap().emplace(index, [fu](int col, Player*) -> std::list<std::unique_ptr<T>> {return fu(col); });
	return true;
}

template<typename T>
bool ObjectFactory<T>::registerIt(int index, func2 fu)
{
	getMap().emplace(index, fu);
	return true;
}


template <typename T>
std::map<int, std::function<std::list<std::unique_ptr<T>>(int, Player*)>>& ObjectFactory<T>::getMap()
{
	static ObjMap map;
	return map;
}


