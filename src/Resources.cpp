#include "Resources.h"
#include <iostream>

Resources::Resources()
{
	//texures
	readData(m_backgroungs, BACKGROUNDS_FILE_NAMES, NUM_OF_BACKGROUNDS);
	readData(m_buttonsTexures, BOTTUNS_FILE_NAMES, NUM_OF_BUTTONS);
	readData(m_objTexures, OBJECT_FILE_NAMES, NUM_OF_OBJECTS);

	//font
	m_font.loadFromFile(FONT_FILE_NAME);

	//IntRect calculation
	appendFrameIntRects("walking berry", 0, { 75, 100 }, 3);
	appendFrameIntRects("jumping berry", 0, { 75, 100 }, 1, 3);
	appendFrameIntRects("walking tank", 23, { 135, 100 }, 2);
	appendFrameIntRects("jumping tank", 23, { 135, 100 }, 1, 2);
	appendFrameIntRects("Gravity", 0, { 73, 100 }, 4);

	appendFrameIntRects("Fall", 0, { 107, 100 }, 4);
	appendFrameIntRects("Dead", 0, { 107, 100 }, 1, 4);

	appendFrameIntRects("Laser", 0, { 101, 420 }, 4);
	appendFrameIntRects("Light", 0, { 300, 236 }, 6);
	appendFrameIntRects("coin", 0, { 40, 40 }, 8);
	appendFrameIntRects("Gmoney", 0, { 100, 91 }, 1);
	appendFrameIntRects("Gpower", 0, { 59, 60 }, 1);
	appendFrameIntRects("Gshield", 0, { 40, 40 }, 1);
	appendFrameIntRects("Gspeed", 0, { 80, 60 }, 1);
	appendFrameIntRects("Scientists", 8, { 45, 67 }, 3);
	appendFrameIntRects("Missile", 0, {100, 64}, 7);
	appendFrameIntRects("FirstWarning", 0, { 65, 100 }, 4);
	appendFrameIntRects("SecondWarning", 0, { 100, 100 },2);
	appendFrameIntRects("Flame", 0, { 26, 45 }, 6);
	appendFrameIntRects("SpeedFlame", 0, { 185, 130 }, 3);

	//sounds
	for (int i = 0; i < NUM_OF_SOUNDES; i++)
	{
		m_sound_buffer[i].loadFromFile(m_SoundNames[i]);
	}


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

const sf::Texture* Resources::getTextureObject(int index) const
{
	return &(m_objTexures[index]);
}

std::vector<sf::IntRect>* Resources::getIntRect(std::string key) const
{
	auto it = m_intRectMap.find(key);
	if (it != m_intRectMap.end()) {
		return const_cast<std::vector<sf::IntRect>*>(&it->second);
	}
	else {
		return nullptr;
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

sf::SoundBuffer* Resources::getSoundBuffer(int index)
{
	return &(m_sound_buffer[index]);
}

void Resources::appendFrameIntRects(std::string key, int middleGap, sf::Vector2i size, int num, int loc)
{
	auto start = sf::Vector2i(0, 0);

	if (loc > 0) {
		start.x += size.x * loc;
		start.x += middleGap * loc;
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

