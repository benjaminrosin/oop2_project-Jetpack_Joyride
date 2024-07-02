#include "Command/MuteCommand.h"
#include "Controller.h"
#include "CollisionHandling.h"

bool MuteCommand::m_muted = false;

MuteCommand::MuteCommand(Controller* con, int key)
	:BoardCommand(con, key)
{
	m_controller->setVolume((!m_muted) * MUSIC_VOLUME);
	CollisionHandling::setVolume((!m_muted) * SOUND_VOLUME);
	m_sp.setColor(((!m_muted) ? sf::Color::Green : sf::Color::Red));
}

void MuteCommand::axecute()
{
	m_controller->setVolume(m_muted * MUSIC_VOLUME);
	CollisionHandling::setVolume(m_muted * SOUND_VOLUME);
	m_sp.setColor(((m_muted) ? sf::Color::Green : sf::Color::Red));

	m_muted = !m_muted;

}
