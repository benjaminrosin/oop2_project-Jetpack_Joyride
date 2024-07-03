#pragma once
#include "Command/MenuSmallCommand.h"
#include <SFML/Graphics.hpp>

class Menu;

class BackCommandMenu : public MenuSmallCommand
{
public:
	virtual void axecute() override;

};
