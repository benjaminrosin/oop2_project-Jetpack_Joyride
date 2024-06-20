#pragma once
#include "Object.h"
#include <memory>

class outOfView
{
public:
	outOfView(int x) : m_limit(x) {};
	
	template <typename T>
	bool operator () (const T& obj)
	{
		return obj->getPosition().x < m_limit;
	};

private:
	int m_limit;
};
