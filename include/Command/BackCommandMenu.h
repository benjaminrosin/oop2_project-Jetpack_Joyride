#pragma once
#include "Command/MenuCommand.h"
#include <SFML/Graphics.hpp>

class Menu;

class BackCommandMenu : public MenuCommand
{
public:
	BackCommandMenu(Menu*);
	virtual void axecute() override;

};
