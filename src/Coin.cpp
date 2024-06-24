#include "Coin.h"
#include "Factory/ObjectFactory.h"

bool Coin::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Coin_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Coin>(col, row));
		return lst; });

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
