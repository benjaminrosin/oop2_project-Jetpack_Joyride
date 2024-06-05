#include <SFML/Graphics.hpp>
#include <chrono>
#include <time.h>
#include "Menu.h"

int main()
{
	srand(time(NULL));
	auto menu = Menu();
	menu.showMenu();

	return 0;
}
