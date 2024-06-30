#include "State/LaserRotatingState.h"
#include "Resources.h"
#include "Objects/Laser.h"

LaserRotatingState::LaserRotatingState()
{
	m_diraction = rand() % 2;
	if (m_diraction == 0) m_diraction--;
}

void LaserRotatingState::rotate(Laser* ls ,float time)
{
	ls->rotate(time * 70 * m_diraction);
}
