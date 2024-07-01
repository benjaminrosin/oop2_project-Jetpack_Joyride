#include "Command/MuteCommand.h"
#include "Controller.h"
#include "CollisionHandling.h"

MuteCommand::MuteCommand(Controller* con, int key)
	:BoardCommand(con, key)
{}

void MuteCommand::axecute()
{
	m_controller->setVolume(m_muted * MUSIC_VOLUME);
	CollisionHandling::setVolume(m_muted * SOUND_VOLUME);

	m_muted = !m_muted;
}
