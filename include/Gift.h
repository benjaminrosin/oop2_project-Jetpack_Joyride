#pragma once
#include <SFML/Graphics.hpp>
#include "StaticGameObjects.h"

class Gift : public StaticGameObjects
{
public:
	Gift(object_code, int, int, std::string);

private:
	static bool m_registered;

};