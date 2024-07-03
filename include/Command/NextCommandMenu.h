#pragma once
#include "Command/MenuCommand.h"
#include <SFML/Graphics.hpp>

class Menu;

class NextCommandMenu : public MenuCommand
{
public:
	NextCommandMenu(Menu*);
	virtual void axecute() override;

};
