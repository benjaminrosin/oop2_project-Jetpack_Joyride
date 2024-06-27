#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "MovingGameObjects.h"
#include "State/MissileAnimationState.h"

class Player;

class Missile:public MovingGameObjects {
public:

	Missile(int, int, Player*);
	//virtual ~Missile();
	virtual void move(sf::Vector2f v2f) override { MovingGameObjects::move(v2f); };
	virtual void move(float x) override { MovingGameObjects::move(x); };
	void setState(std::unique_ptr<MissileAnimationState>);
	void updateState(float);
	
private:
	static bool m_registered;
	//sf::Sprite m_firstAlert;
	//sf::Sprite m_SecondAlert;
	std::unique_ptr<MissileAnimationState> m_currState;
	int m_heightPlayer;
};