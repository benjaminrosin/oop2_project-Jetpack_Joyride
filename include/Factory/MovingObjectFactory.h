#pragma once
#include "MovingGameObjects.h"
#include <memory>
#include <map>


typedef std::map<int, std::unique_ptr<MovingGameObjects>(*)(int, int)> MovingObjMap;

class MovingObjectFactory
{
public:
	static std::unique_ptr<MovingGameObjects> create(int);
	static std::unique_ptr<MovingGameObjects> create(int,int,int); //for debug
	static bool registerIt(int, std::unique_ptr<MovingGameObjects>(*)(int, int));

private:
	static MovingObjMap& getMap();
};
