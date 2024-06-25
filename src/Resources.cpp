#include "Resources.h"
#include <iostream>

Resources::Resources()
{
	//texures
	readData(m_backgroungs, BACKGROUNDS_FILE_NAMES, NUM_OF_BACKGROUNDS);
	readData(m_buttonsTexures, BOTTUNS_FILE_NAMES, NUM_OF_BUTTONS);
	//readData(m_buttonsBoardTexures, BOTTUNS_BOARD_FILE_NAMES, NUM_OF_BUTTONS_BOARD);
	readData(m_objTexures, OBJECT_FILE_NAMES, NUM_OF_OBJECTS);

	//font
	m_font.loadFromFile(FONT_FILE_NAME);

	//IntRect calculation
	appendFrameIntRects("walking berry", 0, { 112, 150 }, 3);
	appendFrameIntRects("jumping berry", 0, { 112, 150 }, 1, 3);
	appendFrameIntRects("walking tank", 37, { 230, 174 }, 2);
	appendFrameIntRects("jumping tank", 0, { 200, 216 }, 1);


	appendFrameIntRects("coin", 0, { 40, 40 }, 8);
	appendFrameIntRects("Gmoney", 0, { 100, 91 }, 1);
	appendFrameIntRects("Gpower", 0, { 59, 60 }, 1);
	appendFrameIntRects("Gshield", 0, { 40, 40 }, 1);
	appendFrameIntRects("Gspeed", 0, { 80, 60 }, 1);
	appendFrameIntRects("Scientists", 10, { 60, 87 }, 3);
	appendFrameIntRects("Missile", 0, {100, 64}, 7);
	appendFrameIntRects("FirstWarning", 0, { 55, 88 }, 4);
	appendFrameIntRects("SecondWarning", 0, { 99, 100 },2);

	

}

Resources& Resources::getInstance()
{
	static Resources instance;
	return instance;
}

const sf::Texture* Resources::getBackground(int index) const
{
	return &(m_backgroungs[index]);
}

const sf::Texture* Resources::getTextureButtons(int index) const
{
	return &(m_buttonsTexures[index]);
}

//const sf::Texture* Resources::getTextureBoardButtons(int index) const
//{
//	return &(m_buttonsBoardTexures[index]);
//}

const sf::Texture* Resources::getTextureObject(int index) const
{
	return &(m_objTexures[index]);
}

//const sf::IntRect Resources::getIntRect(int index) const
//{
//	return BLOCKING_RECT[index];
//}

std::vector<sf::IntRect>* Resources::getIntRect(std::string key) const
{
	auto it = m_intRectMap.find(key);
	if (it != m_intRectMap.end()) {
		return const_cast<std::vector<sf::IntRect>*>(&it->second);
	}
	else {
		return nullptr; // Key not found, return nullptr
	}
}

const sf::Font* Resources::getFont() const
{
	return &m_font;
}

void Resources::readData(sf::Texture arr[], const std::string names[], int num_of_objects)
{
	for (int i = 0; i < num_of_objects; i++)
		{
			arr[i].loadFromFile(names[i]);
		}
}

void Resources::appendFrameIntRects(std::string key, int middleGap, sf::Vector2i size, int num, int loc)
{
	auto start = sf::Vector2i(0, 0);

	if (loc > 0) {
		start.x += size.x * loc;
		start.x += middleGap * (loc-1);
	}

	auto Loc = [&]() {
		auto prev = start;
		start.x += middleGap;
		start.x += size.x;
		return prev;
		};

	for (int i = 0; i < num; i++)
	{
		m_intRectMap[key].push_back(sf::IntRect(Loc(), size));
	}

}

//void Resources::readSpriteSheet(sf::Texture arr[], const std::string names[], int num_of_objects)
//{
//	for (int i = 0; i < num_of_objects; i++)
//		{
//			arr[i].loadFromFile(names[i]);
//
//			auto size = arr[i].getSize();
//			float x = size.x / NUM_OF_TXTR_IN_SHEET[i];
//
//			for (int num = 0; num < NUM_OF_TXTR_IN_SHEET[i]; num++)
//			{
//				m_intRect[i].push_back(sf::IntRect(num * x, 0, x, size.y));
//			}
//
//		}
//}
//
