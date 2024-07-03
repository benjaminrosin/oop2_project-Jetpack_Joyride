#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>

enum object_code {
	Scientists_t, Misssile_t, Laser_t,
	Coin_t, Light_t,
	Gift_t, Gpower_t, Gspeed_t, Gmoney_t,
	Player_t, Tank_t, Gravity_t,
	FirstAlert_t, SecondAlert_t, Dead_t, Flame_t,SpeedFlame_t

};

enum sound_code {
	CoinSound_t, PowerSound_t, MissileHitSound_t, 
	MissileAlarmSound_t, MissileLaunchSound_t, LaserHitSound_t, 
	PiggySound_t, ShieldSpeed_t
};

const sf::Vector2f SCREEN_SIZE(1200, 791);

const float PI = 3.14159265358979323846;
const float GRAVITY = 500;
const int MUSIC_VOLUME = 10;
const int SOUND_VOLUME = 20;
const int NUM_OF_GIFTS = 3;
const int MISSILE_SPEED = 300;
const float ANIMATION_RATE = 0.1;
const int NUM_OF_DATA = 3;
const int MARGIN = SCREEN_SIZE.y/12;
const int DEFULT_START_POINT = SCREEN_SIZE.y - MARGIN;
const float TOP_SCREEN_LIMIT = MARGIN;
const int APPROVED_OVERLAP = 15;
const float START_SPEED = 300;
const sf::Vector2f COIN_SIZE(40, 40);

const int NUM_OF_BACKGROUNDS = 6;
const std::string BACKGROUNDS_FILE_NAMES[NUM_OF_BACKGROUNDS] = {
	"GameMenu.png",
	"Hall.png",
	"help1.png",
	"help2.png",
	"help3.png",
	"Title.png"
};

const int NUM_OF_BUTTONS = 4;
const std::string BOTTUNS_FILE_NAMES[NUM_OF_BUTTONS] = {
	"ButtonMenu.png",
	"mute.png",
	"pause.png",
	"back.png"
};

const int NUM_OF_OBJECTS = 17;
const std::string OBJECT_FILE_NAMES[NUM_OF_OBJECTS] = {
"Scientist.png",
"Missile.png",
"Laser.png",
"Coin.png",
"Lights.png",
"Lights.png",
"PowerUpBox.png",
"speedGift.png",
"Piggy.png",
"JetpackWalking.png",
"SuperPowerTank2.png",
"SuperPowerRunner.png",
"MissileWarning.png",
"MissileIncoming.png",
"PlayerDead.png",
"Exhaust.png",
"speedflame.png"
};

const int NUM_OF_SOUNDES = 8;
const std::string m_SoundNames[NUM_OF_SOUNDES] = {
"coin.wav",
"getPowerSound.wav",
"hitSound.wav",
"MissileAlarm.wav",
"MissileLaunch.wav",
"ZapperSound.wav",
"Piggy.wav",
"ShieldSpeed.ogg"
};

const std::string FONT_FILE_NAME = "New Athletic M54.ttf";
const std::string MASSEGE[] = {
"your score is ",
"please enter your name",
"press enter to continue"
};

class Resources 
{
public:
	static Resources& getInstance();

	const sf::Texture* getBackground(int) const;
	const sf::Texture* getTextureButtons(int) const;
	const sf::Texture* getTextureObject(int) const;
	std::vector<sf::IntRect>* getIntRect(std::string) const;
	const sf::Font* getFont() const;
	sf::SoundBuffer* getSoundBuffer(int);

private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	void readData(sf::Texture[], const std::string[], int);
	void appendFrameIntRects(std::string, int, sf::Vector2i, int, int loc =0);

	sf::Texture m_backgroungs[NUM_OF_BACKGROUNDS];
	sf::Texture m_buttonsTexures[NUM_OF_BUTTONS];
	sf::Texture m_objTexures[NUM_OF_OBJECTS];
	sf::Font m_font;	
	sf::SoundBuffer m_sound_buffer[NUM_OF_SOUNDES];
	std::unordered_map<std::string, std::vector<sf::IntRect>> m_intRectMap;

};