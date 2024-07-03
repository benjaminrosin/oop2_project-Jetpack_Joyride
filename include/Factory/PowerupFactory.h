#pragma once
#include "State/PlayerAnimationState.h"
#include <memory>
#include <map>
#include <list>
#include <functional>
#include <exception>

class Player;

typedef std::function<std::unique_ptr<PlayerAnimationState>(Player*)> Func;
typedef std::map<int, Func> ObjMap;

class PowerupFactory
{
public:
	static std::unique_ptr<PlayerAnimationState> create(int, Player*);

	static bool registerIt(int, Func);

	static int getSize() { return getMap().size(); };

private:
	static ObjMap& getMap();
};

