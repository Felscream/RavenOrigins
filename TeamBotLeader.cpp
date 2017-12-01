#include "TeamBotLeader.h"
#include "Raven_TargetingSystemLeader.h"



TeamBotLeader::TeamBotLeader(Raven_Game* world, Vector2D pos, Team* t) : Raven_Bot(world, pos)
{
	team = t;
	Raven_Bot::m_pTargSys = new Raven_TargetingSystemLeader(this);
}


TeamBotLeader::~TeamBotLeader()
{
	delete Raven_Bot::m_pTargSys;
}
