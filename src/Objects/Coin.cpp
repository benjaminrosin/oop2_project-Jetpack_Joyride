#include "Objects/Coin.h"
#include "Factory/ObjectFactory.h"
#include "Utilities.h"


bool Coin::m_registered =
	(ObjectFactory<Coin>::registerIt(0, createLine)) &&
	(ObjectFactory<Coin>::registerIt(1, createDiagonal)) &&
	(ObjectFactory<Coin>::registerIt(2, createWave)) &&
	(ObjectFactory<Coin>::registerIt(3, createTriangle)) &&
	(ObjectFactory<Coin>::registerIt(4, createCircle)) &&
	ObjectFactory<StaticGameObjects>::registerIt(Coin_t,
	[](int col) -> std::list<std::unique_ptr<StaticGameObjects>> {
		return convertCoinToStaticList(ObjectFactory<Coin>::create(rand() % ObjectFactory<Coin>::getSize(), col, nullptr)); });


Coin::Coin(int col, int row)
	:StaticGameObjects(Coin_t, sf::Vector2f(col, row), "coin")
{
}
