//#pragma once
//#include "StaticGameObjects.h"
//#include <memory>
//#include <map>
//
//typedef std::map<int, std::unique_ptr<StaticGameObjects>(*)(int, int)> StaticObjMap;
//
//class StaticObjectFactory
//{
//public:
//	static std::unique_ptr<StaticGameObjects> create(int);
//	static std::unique_ptr<StaticGameObjects> create(int,int,int); //for debug
//	static bool registerIt(int, std::unique_ptr<StaticGameObjects>(*)(int, int));
//
//private:
//	static StaticObjMap& getMap();
//};
