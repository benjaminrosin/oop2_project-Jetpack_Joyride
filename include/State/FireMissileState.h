#pragma once
#include "State/MissileAnimationState.h"


class FireMissileState : public MissileAnimationState
{
public:
	FireMissileState(Missile*);
	virtual void update(Missile*, float) override;

private:
	float m_timer = 0;
};
