#pragma once
#include "Coin.h"
#include "StaticGameObjects.h"

class  CoinGenerator
{
public:
	static std::list<std::unique_ptr<StaticGameObjects>> generate(int, int);
	static std::list<std::unique_ptr<StaticGameObjects>> createLine(int, int);
	static std::list<std::unique_ptr<StaticGameObjects>> createDiagonal(int, int);
	static std::list<std::unique_ptr<StaticGameObjects>> createWave(int, int);
	//static std::list<std::unique_ptr<StaticGameObjects>> createHeart(int, int);

private:

};
