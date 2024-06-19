#pragma once
#include "Command/MenuCommandInterface.h"

class Menu;

class BackCommand : public MenuCommandInterface
{
public:
	BackCommand();
	virtual void axecute() override;
private:
	Menu& m_menu;
};
