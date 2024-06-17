#include "Resources.h"

Resources::Resources()
{
	//texures
	readData(m_backgroungs, BACKGROUNDS_FILE_NAMES, NUM_OF_BACKGROUNDS);
	readData(m_buttonsTexures, BOTTUNS_FILE_NAMES, NUM_OF_BUTTONS_MENU);
	readData(m_buttonsBoardTexures, BOTTUNS_BOARD_FILE_NAMES, NUM_OF_BUTTONS_BOARD);
	readData(m_objTexures, OBJECT_FILE_NAMES, NUM_OF_OBJECTS);

	//font
	m_font.loadFromFile(FONT_FILE_NAME);

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

const sf::Texture* Resources::getTextureBoardButtons(int index) const
{
	return &(m_buttonsBoardTexures[index]);
}

const sf::Texture* Resources::getTextureObject(int index) const
{
	return &(m_objTexures[index]);
}

const sf::IntRect Resources::getIntRect(int index) const
{
	return BLOCKING_RECT[index];
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
