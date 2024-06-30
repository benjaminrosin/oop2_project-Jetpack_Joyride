#include "Utilities.h"
#include "Coin.h"
#include "StaticGameObjects.h"


std::list<std::unique_ptr<Coin>> createLine(int col, int row)
{
	std::list<std::unique_ptr<Coin>> lst;

	int length = 10 + rand() % 10;
	int thiknes = 1 + rand() % 5;

	if ((thiknes * COIN_SIZE.y) + row > DEFULT_START_POINT)
	{
		thiknes = (DEFULT_START_POINT - row + COIN_SIZE.x) / COIN_SIZE.y;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < thiknes; j++)
		{
			lst.emplace_back(std::make_unique<Coin>(i * COIN_SIZE.x + col, j * COIN_SIZE.y + row));
		}
	}
	return lst;
}


std::list<std::unique_ptr<Coin>> createDiagonal(int col, int row)
{
	std::list<std::unique_ptr<Coin>> lst;
	int length = 10 + rand() % 10;

	// התאמת האורך כדי לא לחרוג מגבולות המסך
	while ((length * COIN_SIZE.y + row) >= DEFULT_START_POINT)
	{
		length--;
	}

	for (int i = 0; i < length; i++)
	{
		int x = i * COIN_SIZE.x + col;
		int y = i * COIN_SIZE.y + row;
		lst.emplace_back(std::make_unique<Coin>(x, y));
	}

	return lst;
}

std::list<std::unique_ptr<Coin>> createWave(int col, int row)
{
	std::list<std::unique_ptr<Coin>> lst;
	int length = 20 + rand() % 10;
	float frequency = 0.1f;  // קובע את תדירות הגל
	float amplitude = COIN_SIZE.y * 3;  // קובע את גובה הגל

	for (int i = 0; i < length; i++)
	{
		int x = i * COIN_SIZE.x + col;
		int y = row + (int(amplitude * sin(frequency * i * PI)));

		// התאמת הערכים כדי לא לחרוג מגבולות המסך
		if (y >= DEFULT_START_POINT)
		{
			y = DEFULT_START_POINT - 1;
		}
		if (y <= MARGIN + COIN_SIZE.y)
		{
			y = MARGIN + COIN_SIZE.y;
		}
		lst.push_back(std::make_unique<Coin>(x, y));
	}
	return lst;
}

std::list<std::unique_ptr<StaticGameObjects>> convertCoinToStaticList(std::list<std::unique_ptr<Coin>>&& coinList) {
	std::list<std::unique_ptr<StaticGameObjects>> baseList;
	for (auto& coin : coinList) {
		baseList.push_back(std::move(coin));
	}
	return baseList;
}
