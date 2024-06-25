#pragma once
#include "State/MissileAnimationState.h"

class AlertMissileState : public MissileAnimationState
{
public:
	virtual void enter(Missile*) override;
	virtual void update(Missile*, float) override;
	virtual void move(float x) override;
private:

};
