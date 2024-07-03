#include "Utilities.h"
#include "Coin.h"
#include "StaticGameObjects.h"
#include <list>
#include <memory>
#include <cmath>
#include <cstdlib> // for rand()


std::list<std::unique_ptr<Coin>> createLine(int col)
{
	int row = randomY();
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


std::list<std::unique_ptr<Coin>> createDiagonal(int col)
{
	int row = randomY();
	std::list<std::unique_ptr<Coin>> lst;
	int length = 10 + rand() % 10;

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

std::list<std::unique_ptr<Coin>> createWave(int col)
{
	int row = randomY();
	std::list<std::unique_ptr<Coin>> lst;
	int length = 20 + rand() % 10;
	float frequency = 0.1f;  
	float amplitude = COIN_SIZE.y * 3;  
	int x;
	int y;
	for (int i = 0; i < length; i++)
	{
		x = i * COIN_SIZE.x + col;
		y = row + (int(amplitude * sin(frequency * i * PI)));

		
		if (y >= DEFULT_START_POINT)
		{
			y = DEFULT_START_POINT - 1;
		}
		if (y <= TOP_SCREEN_LIMIT + COIN_SIZE.y)
		{
			y = TOP_SCREEN_LIMIT + COIN_SIZE.y;
		}
		lst.push_back(std::make_unique<Coin>(x, y));
	}
	return lst;
}


std::list<std::unique_ptr<Coin>> createTriangle(int col)
{
	int row = randomY();
	std::list<std::unique_ptr<Coin>> lst;

	int size = 5+ rand() % 5;  

	//if (row + size * COIN_SIZE.y < TOP_SCREEN_LIMIT || row + size * COIN_SIZE.y >= DEFULT_START_POINT) {
	//	return {};
	//}

	for (int i = 0; i <= size; ++i) {
		int y = row + i * COIN_SIZE.y;
		int startX = col - (i * COIN_SIZE.x / 2);
		int endX = col + (i * COIN_SIZE.x / 2);

		if (y > DEFULT_START_POINT || y < TOP_SCREEN_LIMIT) {
			continue;
		}

		for (int x = startX; x <= endX; x += COIN_SIZE.x) {
			lst.push_back(std::make_unique<Coin>(x, y));
		}
	}

	return lst;
}


std::list<std::unique_ptr<Coin>> createCircle(int col) 
{
	int row = randomY();
	std::list<std::unique_ptr<Coin>> lst;

	int radius = 2 + rand() % 5; 
	int param = 2 * PI * radius;
	/*
	if (row - COIN_SIZE.y * radius - COIN_SIZE.y <= TOP_SCREEN_LIMIT || row + COIN_SIZE.y * radius >= DEFULT_START_POINT) {
		return {}; 
	}*/

	for (int angle = 0; angle <= 360; angle += 360/param) { 
		double radians = angle * PI / 180.0;
		int x = col + COIN_SIZE.x * radius * std::cos(radians);
		int y = row + COIN_SIZE.y * radius * std::sin(radians);
		if (y < DEFULT_START_POINT && y > TOP_SCREEN_LIMIT) {
			lst.push_back(std::make_unique<Coin>(x, y));
		}
	}

	return lst;
}


int randomY()
{
	return 2 * MARGIN + (rand() % ((DEFULT_START_POINT - 2 * MARGIN) / 10)) * 10;
}


std::list<std::unique_ptr<StaticGameObjects>> convertCoinToStaticList(std::list<std::unique_ptr<Coin>>&& coinList) {
	std::list<std::unique_ptr<StaticGameObjects>> baseList;
	for (auto& coin : coinList) {
		baseList.push_back(std::move(coin));
	}
	return baseList;
}

