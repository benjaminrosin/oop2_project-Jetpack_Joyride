#pragma once
#include "Object.h"
#include <memory>
#include <map>


typedef std::map<int, std::unique_ptr<Object>(*)(int, int)> objMap;

class ObjectFactory
{
public:
	static std::unique_ptr<Object> create(int);
	static std::unique_ptr<Object> create(int,int,int); //for debug
	static bool registerIt(int, std::unique_ptr<Object>(*)(int, int));

private:
	static objMap& getMap();
};
