#include "Board.h"
#include "State/JumpAnimationPlayerState.h"
#include "State/WalkAnimationPlayerState.h"
#include <iostream>
#include <fstream>
#include <memory>
#include "Factory/ObjectFactory.h"
#include "Gift.h";
#include "Gshield.h";
#include "Gspeed.h";
#include "Gpower.h";
#include "Gmoney.h";
#include "Utilities.h"
#include "CollisionHandling.h"



Board::Board()
{
	//m_objects.clear();
	m_player = std::make_unique<Player>();

}

void Board::play(sf::RenderWindow& wind, float timer, float delta_time)//לשים לב שיש גם טיימר וגם דלתא
{
	//player's move
	m_player->update(delta_time);

	//handle collision
	m_statics.remove_if([&](auto& obj){ return (collide(*obj.get()) && CollisionHandling::processCollision(*m_player, *obj)); });
	m_movings.remove_if([&](auto& obj){ return (collide(*obj.get()) && CollisionHandling::processCollision(*m_player, *obj)); });

	
	//std::for_each(m_movings.begin(), m_movings.end(), [&](auto& obj) {if (obj != nullptr) obj->move_and_change_sprite(delta_time, &(*m_player)); });*/

	std::for_each(m_movings.begin(), m_movings.end(), [&](auto& obj) {obj->move(delta_time); });

	std::for_each(m_statics.begin(), m_statics.end(), [&](auto& obj) {obj->animate(delta_time); });
	//animate

	m_objTimer -= delta_time;

	//if (m_objTimer < 0)
	//{
		readLevel(wind, delta_time);
	//	m_objTimer = 1;
	//}

	//removing odjects that out of view
	int xView = wind.getView().getCenter().x - SCREEN_SIZE.x;
	m_movings.remove_if(outOfView(xView));
	m_statics.remove_if(outOfView(xView));

}

void Board::draw(sf::RenderWindow& wind) const
{
	std::for_each(m_movings.begin(), m_movings.end(), [&wind](auto& obj)  { /*if (obj != nullptr)*/ obj->draw(wind); });
	std::for_each(m_statics.begin(), m_statics.end(), [&wind](auto& obj)  { /*if (obj != nullptr)*/ obj->draw(wind); });
	
	m_player->draw(wind);
	//wind.draw(m_player->getDrawable());
	//std::for_each(m_objects.begin(), m_objects.end(), [&wind](auto &obj) {if (obj != nullptr) wind.draw(obj->getDrawable()); });

}
//
//bool Board::checkCollision()
//{
//	return false;
//}

void Board::readLevel(sf::RenderWindow& wind, float delta_time)
{
	static float timeToGift = 5;
	static float timeToCoins = 5;
	auto x = wind.getView().getCenter().x + SCREEN_SIZE.x;
	timeToGift -= delta_time;
	timeToCoins -= delta_time;
	//int obj = rand() % 10 + 1;
	if (timeToCoins < 0)
	{
		m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Coin_t, x, randomY()));
		timeToCoins = 5 + rand() % 5;
	}
	if (timeToGift < 0)
	{
		m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Gift_t, x, randomY()));
		timeToGift = 5 + rand() % 15;
	}

	if (m_objTimer < 0)
	{
		m_movings.splice(m_movings.end(), ObjectFactory<MovingGameObjects>::create(Scientists_t, x, 600));
		m_objTimer = 1;
	}

	/*m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Gspeed_t, x, 350));
	m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Gshield_t, x, 300));
	m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Gmoney_t, x, 550));
	m_statics.splice(m_statics.end(), ObjectFactory<StaticGameObjects>::create(Gpower_t, x, 450));*/

	//m_statics.push_back(ObjectFactory<StaticGameObjects>::create(Coin_t, x, 500));
	//m_statics.push_back(ObjectFactory<StaticGameObjects>::create(Gspeed_t, x, 350));
	//m_statics.push_back(ObjectFactory<StaticGameObjects>::create(Gshield_t, x, 300));
	//m_statics.push_back(ObjectFactory<StaticGameObjects>::create(Gmoney_t, x, 550));
	//m_statics.push_back(ObjectFactory<StaticGameObjects>::create(Gpower_t, x, 450));
	//m_statics.insert(coinsgener);
	//m_movings.push_back(ObjectFactory<MovingGameObjects>::create(Scientists_t, x, 600));

	//m_statics.push_back(ObjectFactory<StaticGameObjects>::create(Gift_t, x, 450));


	//x = rand() % 5;

	/*if (x==Coin_t){
		m_statics.insert(coinsgener);
	}
	else if (x<)*/

	/*switch (rand() % NUM_OF_GIFTS)
	{
	case 0:
		m_objects.push_back(ObjectFactory::create(Gmoney_t, x, 350));
		break;
	case 1:
		m_objects.push_back(ObjectFactory::create(Gpower_t, x, 450));
		break;
	case 2:
		m_objects.push_back(ObjectFactory::create(Gshield_t, x, 400));
		break;
	case 3:
		m_objects.push_back(ObjectFactory::create(Gspeed_t, x, 350));
		break;
	}*/



	////for now the func will read level from txt file, hopfully 
	////the game will ganarate its levels
	//char c;
	//auto file = std::ifstream("level.txt");
	//int col = 0;
	//int row = 0;

	//while (file.get(c))
	//{
	//	if (c == '\n')
	//	{
	//		row = 0;
	//		col++;
	//		continue;
	//	}

	//	else if (c != '-')
	//	{
	//		auto temp = ObjectFactory::create(c);
	//		if (temp != nullptr) {
	//			m_objects.push_back(std::move(temp));
	//		}
	//		
	//	}
	//	row++;
	//}
}

bool Board::alive() const
{
	return true;
}

sf::Vector2f Board::getPlayerLoc() const
{
	return m_player->getPosition();
}

bool Board::collide(Object& obj)
{
	sf::FloatRect overlapRect;

	if (m_player->getGlobalBounds().intersects(obj.getGlobalBounds(), overlapRect))
	{
		if (overlapRect.height > APPROVED_OVERLAP && overlapRect.width > APPROVED_OVERLAP)//קונסט!!!!
		{
			return true;
		}
	}

	return false;
}

int Board::randomY() const
{

	return 2*MARGIN + (rand()% ((DEFULT_START_POINT - 2*MARGIN) / 10))*10 ;

}

//void Board::findCollision(std::list<std::unique_ptr<Object>>& objects)
//{
//	std::for_each(objects.begin(), objects.end(), [&](auto& obj) 
//		{if (collide(obj)) objects.remove_if(CollisionHandling::processCollision(*m_player, *obj)); });
//}


//void Board::deleteObjects(sf::RenderWindow& wind)
//{
//	int xView = wind.getView().getCenter().x - SCREEN_SIZE.x;
//
//	for (auto& obj : m_objects) 
//	{
//		if (obj->getPosition().x < xView) {
//
//		}
//
//	}
//
//	
//
//	for (int i = 0; i < m_objects.size(); i++) {
//		{
//
//		}
//	}
//}

