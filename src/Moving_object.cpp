#include "Moving_object.h"

Moving_object::Moving_object(object_code obj, sf::Vector2f loc)
	:Object(Resources::getInstance().getTextureObject(obj), loc, Resources::getInstance().getIntRect(obj))
{}

