#pragma once
#include "Command/MenuCommand.h"
#include <SFML/Graphics.hpp>

class Menu;

class BackCommandMenu : public MenuCommand
{
public:
	BackCommandMenu(Menu*, std::string);
	virtual void axecute() override;
private:

public:

};
