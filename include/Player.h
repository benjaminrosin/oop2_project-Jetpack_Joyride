#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Object.h"
#include "PlayerAnimationState.h"



class Player:public Object {
public:
	Player();
	virtual ~Player() {};
	void move_and_change_sprite(float, Object*)override;
	virtual float getHeight() const;
	void setState(std::unique_ptr<PlayerAnimationState>);
	void update(float);
	//void draw(sf::RenderWindow&);
	void jump();
	void walk();
	void handleSpaceRelease();

	//
	//virtual void draw(sf::RenderWindow&)const {};
	//virtual sf::Vector2f getPosition() const {};
	//virtual void move(sf::Vector2f) {};
	//virtual void move_and_change_sprite(float, Object*) = 0;
	//virtual void setSpriteRect(sf::IntRect) {};


	
private:
	std::unique_ptr<PlayerAnimationState> m_currentState;
};