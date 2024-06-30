#pragma once
#include "State/MissileAnimationState.h"

class AlertMissileState : public MissileAnimationState
{
public:
	AlertMissileState(Missile*);
	virtual void update(Missile*, float) override;

private:
	float m_timer = 0;
	bool m_firstTime = true;
	
};
