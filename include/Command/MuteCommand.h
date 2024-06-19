#pragma once
#include "Command/MenuCommandInterface.h"

class Menu;

class MuteCommand : public MenuCommandInterface
{
public:
	MuteCommand();
	virtual void axecute() override;
private:
	Menu& m_menu;
};
