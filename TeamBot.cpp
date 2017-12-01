#include "TeamBot.h"
#include "Raven_TargetingSystemTeam.h"


TeamBot::TeamBot(Raven_Game* world, Vector2D pos, Team* t) : Raven_Bot(world, pos)
{
	team = t;
	Raven_Bot::m_pTargSys = new Raven_TargetingSystemTeam(this);
}


TeamBot::~TeamBot()
{
	delete Raven_Bot::m_pTargSys;
}
