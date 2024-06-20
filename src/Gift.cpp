#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Factory/StaticObjectFactory.h"

bool Gift::m_registered = StaticObjectFactory::registerIt(Gift_t, 
	[](int col, int row) -> std::unique_ptr<StaticGameObjects> { 
		return StaticObjectFactory::create(rand()%NUM_OF_GIFTS + Gift_t + 1); });



Gift::Gift(object_code obj, int col, int row)
	:StaticGameObjects(obj, sf::Vector2f(col, row))
{
}
