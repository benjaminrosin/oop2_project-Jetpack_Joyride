#include "Coin.h"
#include "Factory/ObjectFactory.h"
//#include "CoinGenerator.h"
#include "Utilities.h"


bool Coin::m_registered =
	(ObjectFactory<Coin>::registerIt(0, createLine)) &&
	(ObjectFactory<Coin>::registerIt(1, createDiagonal)) &&
	(ObjectFactory<Coin>::registerIt(2, createWave)) &&
	ObjectFactory<StaticGameObjects>::registerIt(Coin_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		return convertCoinToStaticList(ObjectFactory<Coin>::create(rand() % ObjectFactory<Coin>::getSize() , col, row, nullptr)); });


Coin::Coin(int col, int row)
	:StaticGameObjects(Coin_t, sf::Vector2f(col, row), "coin")
{
}




//
//bool Coin::m_registered = ObjectFactory::registerIt('*', []() -> std::unique_ptr<Object> { return std::make_unique<Coin>(); });
//
//
//
//Coin::Coin(int col, int row)
//	:NonStatedObject(Coin_t, sf::Vector2f(col, row))
//{
//}
