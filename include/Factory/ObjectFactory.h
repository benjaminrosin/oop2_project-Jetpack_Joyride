#pragma once
#include "MovingGameObjects.h"
#include "StaticGameObjects.h"
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
	//typedef (std::list<std::unique_ptr<T>>(*)(int, int, Player*)) func;
	typedef std::map<int, func2> ObjMap;

	//static std::list<std::unique_ptr<T>> create(int);
	static std::list<std::unique_ptr<T>>  create(int, int, Player*); 

	static bool registerIt(int, func1);
	static bool registerIt(int, func2);

	static int getSize() { return getMap().size(); };

private:
	static ObjMap& getMap();
};

//template <typename T>
//std::list<std::unique_ptr<T>> ObjectFactory<T>::create(int index)
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
//	return it->second(5,5, nullptr);
//	//adding pram
//}

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

//template<typename T>
//int ObjectFactory<T>::getSize() const
//{
//	return ;
//}


//template<typename T>
//inline bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int, Player*))
//{
//	getMap().emplace(index, fu);
//	return true;
//}

//template <typename T>
//bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int, Player*))
//{
//	getMap().emplace(index, fu);
//	return true;
//}

//template <typename T>
//bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int))
//{
//	getMap().emplace(index, [fu](col, row, player*) { return fu(col, row); });
//	return true;
//}
// 
//template <typename T>
//bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int, player*))
//{
//	getMap().emplace(index, fu);
//	return true;
//}


