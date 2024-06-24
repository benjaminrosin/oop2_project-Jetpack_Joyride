#pragma once
#include "Coin.h"
#include "StaticGameObjects.h"

class  CoinGenerator
{
public:
	static std::list<std::unique_ptr<StaticGameObjects>> generate(int, int);
	static std::list<std::unique_ptr<StaticGameObjects>> createLine(int, int);

private:

};
