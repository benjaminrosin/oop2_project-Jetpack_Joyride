#include <SFML/Graphics.hpp>
#include "Objects/Gift.h"
#include "Factory/ObjectFactory.h"

bool Gift::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Gift_t,
	[](int col) -> std::list<std::unique_ptr<StaticGameObjects>> {
		return ObjectFactory<StaticGameObjects>::create(rand()%NUM_OF_GIFTS + Gift_t + 1, col, nullptr); });

Gift::Gift(object_code obj, int col, int row, std::string key)
	:StaticGameObjects(obj, sf::Vector2f(col, row), key)
{ 
}
