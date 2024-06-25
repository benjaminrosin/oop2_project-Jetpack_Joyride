#include "Objects/Missile.h"
#include "Factory/ObjectFactory.h"

bool Missile::m_registered = ObjectFactory<MovingGameObjects>::registerIt(FirstAlert_t,
	[](int col, int row) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Missile>(col, row));
		return lst; });


Missile::Missile(int col, int row)
	:MovingGameObjects(FirstAlert_t, sf::Vector2f(SCREEN_SIZE.x, row), "FirstWarning")
{
}
