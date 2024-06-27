#include "Objects/Light.h"
#include "Factory/ObjectFactory.h"

bool Light::m_registered = ObjectFactory<StaticGameObjects>::registerIt(Light_t,
	[](int col, int row) -> std::list<std::unique_ptr<StaticGameObjects>> {
		std::list<std::unique_ptr<StaticGameObjects>> lst;
		lst.push_back(std::make_unique<Light>(col, row));
		return lst; });

Light::Light(int col, int row)
	:StaticGameObjects(Light_t, sf::Vector2f(col, 4*MARGIN), "Light")
{
}