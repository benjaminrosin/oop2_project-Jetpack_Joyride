#include "Coin.h"
#include "ObjectFactory.h"

bool Coin::m_registered = ObjectFactory::registerIt(Coin_t, [](int col, int row) -> std::unique_ptr<Object> { return std::make_unique<Coin>(col, row); });

Coin::Coin(int col, int row)
	:NonStatedObject(Coin_t, sf::Vector2f(col, row))
{
}

void Coin::move_and_change_sprite(float, Object*)
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
