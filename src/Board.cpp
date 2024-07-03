#include "Board.h"
#include "State/JumpAnimationPlayerState.h"
#include "State/WalkAnimationPlayerState.h"
#include <iostream>
#include <fstream>
#include <memory>
#include "Factory/ObjectFactory.h"
#include "Gift.h";
#include "Gspeed.h";
#include "Gpower.h";
#include "Gmoney.h";
#include "Utilities.h"
#include "CollisionHandling.h"


Board::Board()
{
	m_player = std::make_unique<Player>();
}

void Board::play(sf::RenderWindow& wind, float delta_time)
{
	//player move
	m_player->update(delta_time);

	// Goes over all objects.
	// If there was a collision between the player and the object, the collision will be realized.
	// If it is an object that needs to be deleted after a collision, we will drop it from the list.
	if (!m_player->avoidCollisions()) {
		m_statics.remove_if([&](auto& obj) { return (collide(*obj.get()) && CollisionHandling::processCollision(*m_player, *obj)); });
		m_movings.remove_if([&](auto& obj) { return (collide(*obj.get()) && CollisionHandling::processCollision(*m_player, *obj)); });
	}
	
	//Perform movement for all the moving objects
	std::for_each(m_movings.begin(), m_movings.end(), [&](auto& obj) {obj->move(delta_time); });

	//Perform animation for all the static objects
	std::for_each(m_statics.begin(), m_statics.end(), [&](auto& obj) {obj->animate(delta_time); });
	
	//create objects on the screen throughout the game.
	generateLevel(wind, delta_time);
	
	//removing odjects that out of view using func-tor
	int xView = wind.getView().getCenter().x - SCREEN_SIZE.x;
	m_movings.remove_if(outOfView(xView));
	m_statics.remove_if(outOfView(xView));

}

void Board::draw(sf::RenderWindow& wind) const
{
	std::for_each(m_statics.begin(), m_statics.end(), [&wind](auto& obj) { obj->draw(wind); });
	std::for_each(m_movings.begin(), m_movings.end(), [&wind](auto& obj)  { obj->draw(wind); });
	
	m_player->draw(wind);
}

void Board::generateLevel(sf::RenderWindow& wind, float delta_time)
{
	// firs rand
	static float timeToGift = rand() % 5;
	static float timeToCoins = rand() % 5;
	static float timeToLaser = rand() % 5;
	static float timeToMissile = 20 + rand() % 20;
	static float timeToDecor = rand() % 3;

	auto playerSpeed = m_player->getSpeed();

	auto x = wind.getView().getCenter().x + SCREEN_SIZE.x;

	// update timers
	timeToGift -= delta_time; 
	timeToCoins -= delta_time;
	timeToLaser -= delta_time;
	timeToMissile -= delta_time;
	timeToDecor -= delta_time; 

	// craeting the objects and raffle the next timer
	if (timeToCoins < 0)
	{
		m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Coin_t, x, m_player.get()));
		timeToCoins = (3 + rand() % 5) * (START_SPEED / playerSpeed);
	}
	if (timeToGift < 0)
	{
		m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Gift_t, x, m_player.get()));
		timeToGift = (5 + rand() % 15) * (START_SPEED / playerSpeed);
	}
	if (timeToLaser < 0)
	{
		m_movings.splice(m_movings.end(), ObjectFactory<MovingGameObjects>::create(Laser_t, x, m_player.get()));
		timeToLaser = (3 + rand() % 15) * (START_SPEED / playerSpeed);
	}
	if (timeToMissile < 0)
	{
		m_movings.splice(m_movings.end(), ObjectFactory<MovingGameObjects>::create(Misssile_t, x, m_player.get()));
		timeToMissile = (10 + rand() % 20) * (START_SPEED / playerSpeed);
	}
	if (timeToDecor < 0)
	{
		int obj = rand() % 2;
		if (obj)
		{
			m_movings.splice(m_movings.end(), ObjectFactory<MovingGameObjects>::create(Scientists_t, x, m_player.get()));
		}
		else
		{
			m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Light_t, x, m_player.get()));
		}
		timeToDecor = (1 + rand() % 3) * (START_SPEED / playerSpeed);
	}

}

bool Board::alive() const
{
	return !m_player->isDead();
}

sf::Vector2f Board::getPlayerLoc() const
{
	return m_player->getPosition();
}

bool Board::collide(Object& obj)
{
	sf::FloatRect overlapRect;

	sf::FloatRect newPlayerBounds = obj.getTransform().getInverse().transformRect(m_player->getGlobalBounds());
	if (newPlayerBounds.intersects(obj.getLocalBounds(), overlapRect))
	{
		if (overlapRect.height > APPROVED_OVERLAP && overlapRect.width > APPROVED_OVERLAP)
		{
			return true;
		}
	}

	return false;
}


