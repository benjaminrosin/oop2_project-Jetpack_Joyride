#include "Objects/Missile.h"
#include "Factory/ObjectFactory.h"
#include "State/AlertMissileState.h"

bool Missile::m_registered = ObjectFactory<MovingGameObjects>::registerIt(FirstAlert_t,
	[](int col, int row) -> std::list<std::unique_ptr<MovingGameObjects>> {
		std::list<std::unique_ptr<MovingGameObjects>> lst;
		lst.push_back(std::make_unique<Missile>(col, row));
		return lst; });


Missile::Missile(int col, int row)
	:MovingGameObjects(FirstAlert_t, sf::Vector2f(col, row), "FirstWarning")
{
	setState(std::make_unique<AlertMissileState>());
}

void Missile::setState(std::unique_ptr<MissileAnimationState> state)
{
	m_currState = std::move(state);
	m_currState->enter(this);
}

void Missile::updateState(float deltaTime)
{
	m_currState->update(this, deltaTime);
}
