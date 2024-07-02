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


std::list<std::unique_ptr<Coin>> createLine(int);
std::list<std::unique_ptr<Coin>> createDiagonal(int);
std::list<std::unique_ptr<Coin>> createWave(int);
std::list<std::unique_ptr<Coin>> createTriangle(int);
std::list<std::unique_ptr<Coin>> createCircle(int);
int randomY();

std::list<std::unique_ptr<StaticGameObjects>> convertCoinToStaticList(std::list<std::unique_ptr<Coin>>&&);
