#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"
#include "State/MissileAnimationState.h"

class Player;

class Missile:public MovingGameObjects {
public:

	Missile(int, int, Player*);
	virtual void move(sf::Vector2f v2f) override { MovingGameObjects::move(v2f); };
	virtual void move(float x) override;
	void setState(std::unique_ptr<MissileAnimationState>);
	//void update(float);
	void setPositionByPlayer();
	virtual void playSound(const sf::SoundBuffer*);

private:
	static bool m_registered;
	std::unique_ptr<MissileAnimationState> m_currState;
	Player* m_p2player;
	float m_timer = 0;
	bool m_firstTime = true;
	sf::Sound m_currSound;
};