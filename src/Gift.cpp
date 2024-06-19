#include <SFML/Graphics.hpp>
#include "Gift.h"


Gift::Gift(object_code obj, int col, int row)
	:GameObjects(obj, sf::Vector2f(col, row))
{
}
