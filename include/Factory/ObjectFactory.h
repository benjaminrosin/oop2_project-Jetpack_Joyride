#pragma once
#include "MovingGameObjects.h"
#include "StaticGameObjects.h"
#include <memory>
#include <map>
#include <list>

class Player;


//template <typename T>
//typedef std::map<int, std::unique_ptr<T>(*)(int, int)> ObjMap;

template <typename T>
class ObjectFactory
{
public:
	typedef std::map<int, std::list<std::unique_ptr<T>>(*)(int, int, Player*)> ObjMap;

	//static std::list<std::unique_ptr<T>> create(int);
	static std::list<std::unique_ptr<T>>  create(int,int,int, Player*); //for debug

	static bool registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int));
	static bool registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int, Player*));

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
std::list<std::unique_ptr<T>> ObjectFactory<T>::create(int index, int x, int y, Player* p) //for debug
{
	auto it = getMap().find(index);
	if (it == getMap().end())
	{
		//return NULL;
		//throw exeption
	}

	return it->second(x,y,p);
	//adding pram
}

template <typename T>
bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int))
{
	getMap().emplace(index, [fu](int col, int row, Player*) -> std::list<std::unique_ptr<T>> {return fu(col, row); });
	return true;
}

template<typename T>
inline bool ObjectFactory<T>::registerIt(int index, std::list<std::unique_ptr<T>>(*fu)(int, int, Player*))
{
	getMap().emplace(index, fu);
	return true;
}




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


template <typename T>
std::map<int, std::list<std::unique_ptr<T>>(*)(int, int, Player*)>& ObjectFactory<T>::getMap()
{
	static ObjMap map;
	return map;
}
