#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

enum object_code {
	Player_t, Coin_t
};

const sf::IntRect BLOCKING_RECT[] = {
	sf::IntRect(0, 0, 112.5, 150)
};

const sf::Vector2f SCREEN_SIZE(1200, 791);
//const sf::Vector2f MESSAGE_SCREEN_SIZE(600, 300);
const int NUM_OF_DATA = 2;
const int MARGIN = SCREEN_SIZE.y/12;

const int NUM_OF_BACKGROUNDS = 3;
const std::string BACKGROUNDS_FILE_NAMES[NUM_OF_BACKGROUNDS] = {
	"GameMenu.png",
	"Hall.png",
	"help.png"
};

const int NUM_OF_BUTTONS_MENU = 4;
const std::string BOTTUNS_FILE_NAMES[NUM_OF_BUTTONS_MENU] = {
	"play.png",
	"continue.png",
	"rules.png",
	"exit.png"
};


//add textures
const int NUM_OF_BUTTONS_BOARD = 3;
const std::string BOTTUNS_BOARD_FILE_NAMES[NUM_OF_BUTTONS_BOARD] = {
"back.png",
"pause.png",
"mute.png"
};

//add textures
const int NUM_OF_OBJECTS = 1;
const std::string OBJECT_FILE_NAMES[NUM_OF_BUTTONS_BOARD] = {
"JetpackWalking.png"
};

//const int NUM_OF_SOUNDES = 7;
//const std::string SOUND_FILE_NAME[NUM_OF_SOUNDES] = {
//"success.ogg",
//"loss.ogg",
//"bite.ogg",
//"door open.ogg",
//"gift.ogg",
//"collect key.ogg",
//"door collision.ogg"
//};

const std::string FONT_FILE_NAME = "LoveDays-2v7Oe.ttf";


class Resources 
{
public:
	static Resources& getInstance();

	const sf::Texture* getBackground(int) const;
	const sf::Texture* getTextureButtons(int) const;
	const sf::Texture* getTextureBoardButtons(int) const;
	const sf::Texture* getTextureObject(int) const;
	const sf::IntRect getIntRect(int) const;
	//sf::SoundBuffer* getSoundBuffer(int);
	const sf::Font* getFont() const;


private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	void readData(sf::Texture[], const std::string[], int);
	sf::Texture m_backgroungs[NUM_OF_BACKGROUNDS];
	sf::Texture m_buttonsTexures[NUM_OF_BUTTONS_MENU];
	sf::Texture m_buttonsBoardTexures[NUM_OF_BUTTONS_MENU];
	sf::Texture m_objTexures[NUM_OF_OBJECTS];
	//sf::SoundBuffer m_sound_buffer[NUM_OF_SOUNDES];
	sf::Font m_font;

};