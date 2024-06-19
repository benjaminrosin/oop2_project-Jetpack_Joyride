#pragma once
#include "Object.h"
#include <memory>

class outOfView
{
public:
	outOfView(int x) : m_limit(x) {};
	
	bool operator () (const std::unique_ptr<Object>& obj)
	{
		return obj->getPosition().x < m_limit;
	};

private:
	int m_limit;
};
