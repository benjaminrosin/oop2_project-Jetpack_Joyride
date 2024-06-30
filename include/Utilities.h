#pragma once
#include "Object.h"
#include <memory>

class Coin;
class StaticGameObjects;

class outOfView
{
public:
	outOfView(int x) : m_limit(x) {};
	
	template <typename T>
	bool operator () (const T& obj)
	{
		return obj->getPosition().x < m_limit;
	};

private:
	int m_limit;
};


std::list<std::unique_ptr<Coin>> createLine(int, int);
std::list<std::unique_ptr<Coin>> createDiagonal(int, int);
std::list<std::unique_ptr<Coin>> createWave(int, int);

std::list<std::unique_ptr<StaticGameObjects>> convertCoinToStaticList(std::list<std::unique_ptr<Coin>>&&);
