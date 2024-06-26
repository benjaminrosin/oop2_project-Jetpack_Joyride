#include "State/LaserRotatingState.h"
#include "Resources.h"
#include "Objects/Laser.h"

void LaserRotatingState::enter()
{}


void LaserRotatingState::rotate(Laser* ls ,float time)
{
	ls->rotate(time * 70);
}
