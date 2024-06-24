#include "CoinGenerator.h"

std::list<std::unique_ptr<StaticGameObjects>> CoinGenerator::generate(int col, int row)
{
	return createLine(col, row); /*std::list<std::unique_ptr<StaticGameObjects>>();*/
}

std::list<std::unique_ptr<StaticGameObjects>> CoinGenerator::createLine(int col, int row)
{
	std::list<std::unique_ptr<StaticGameObjects>> lst;

	int length = 10 + rand() % 10;
	int thiknes = 1 + rand() % 5;

	if ((thiknes * COIN_SIZE.y) + row > DEFULT_START_POINT)
	{
		thiknes = (DEFULT_START_POINT - row + COIN_SIZE.x) / COIN_SIZE.y;

		//thiknes = (thiknes + row - (DEFULT_START_POINT / COIN_SIZE.y));
		//thiknes = thiknes + row - DEFULT_START_POINT;
		//thiknes = 1;
	}

	//auto coinSize = sf::Vector2f(40, 40);

	for (int i = 0; i < length ; i++)
	{
		for (int j = 0; j < thiknes; j++)
		{
			lst.push_back(std::make_unique<Coin>(i* COIN_SIZE.x + col, j* COIN_SIZE.y + row));
		}
	}
	return lst;
}
