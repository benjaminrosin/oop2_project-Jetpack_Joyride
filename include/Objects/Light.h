#pragma once
#include "StaticGameObjects.h"


class Light :public StaticGameObjects
{
public:

	Light(int, int);

private:
	static bool m_registered;


};
