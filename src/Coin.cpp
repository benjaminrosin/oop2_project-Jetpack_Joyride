#include "Coin.h"
#include "ObjectFactory.h"

bool Coin::m_registered = ObjectFactory::registerIt('*', []() -> std::unique_ptr<Object> { return std::make_unique<Coin>(); });

Coin::Coin(int col, int row)
	:NonStatedObject(Coin_t, sf::Vector2f(col, row))
{
}
