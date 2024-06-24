#pragma once
#include "MovingGameObjects.h"
#include "StaticGameObjects.h"
#include <memory>
#include <map>
#include <list>


//template <typename T>
//typedef std::map<int, std::unique_ptr<T>(*)(int, int)> ObjMap;

template <typename T>
class ObjectFactory
{
public:
	typedef std::map<int, std::list<std::unique_ptr<T>>(*)(int, int)> ObjMap;

	static std::list<std::unique_ptr<T>> create(int);
	static std::list<std::unique_ptr<T>>  create(int,int,int); //for debug
	static bool registerIt(int, std::list<std::unique_ptr<T>>(*)(int, int));

private:
	static ObjMap& getMap();
};

template <typename T>
std::list<std::unique_ptr<T>> ObjectFactory<T>::create(int index)
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

template <typename T>
std::list<std::unique_ptr<T>> ObjectFactory<T>::create(int index, int x, int y) //for debug
{
	auto it = getMap().find(index);
	if (it == getMap().end())
	{
		//return NULL;
	}

	return it->second(x,y);
	//adding pram
}

template <typename T>
bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int))
{
	getMap().emplace(index, fu);
	return true;
}


template <typename T>
std::map<int, std::list<std::unique_ptr<T>>(*)(int, int)>& ObjectFactory<T>::getMap()
{
	static ObjMap map;
	return map;
}
