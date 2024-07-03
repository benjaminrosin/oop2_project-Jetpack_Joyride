#pragma once
#include "Command/MenuCommand.h"
#include <SFML/Graphics.hpp>

class Menu;

class PrevCommandMenu : public MenuCommand
{
public:
	PrevCommandMenu(Menu*);
	virtual void axecute() override;

};
