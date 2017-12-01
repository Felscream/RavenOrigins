#include "Raven_TargetingSystemLeader.h"
#include "Raven_Bot.h"
#include "TeamBotLeader.h"
#include "Raven_SensoryMemory.h"




Raven_TargetingSystemLeader::Raven_TargetingSystemLeader(Raven_Bot* owner) : Raven_TargetingSystem(owner)
{
}


Raven_TargetingSystemLeader::~Raven_TargetingSystemLeader()
{
}

void Raven_TargetingSystemLeader::Update()
{
	bool isTeamMember;
	double ClosestDistSoFar = MaxDouble;
	Raven_TargetingSystem::m_pCurrentTarget = 0;
	TeamBotLeader* leader = (TeamBotLeader*) Raven_TargetingSystem::m_pOwner;
	std::list<TeamBot*> members = leader->GetTeam()->GetMembers();
	std::list<TeamBot*>::iterator curMember = members.begin();

	//grab a list of all the opponents the owner can sense
	std::list<Raven_Bot*> SensedBots;
	SensedBots = Raven_TargetingSystem::m_pOwner->GetSensoryMem()->GetListOfRecentlySensedOpponents();

	std::list<Raven_Bot*>::const_iterator curBot = SensedBots.begin();
	for (curBot; curBot != SensedBots.end(); ++curBot)
	{
		isTeamMember = false;

		for (curMember; curMember != members.end(); curMember++) {
			Raven_Bot* bot = (Raven_Bot*) *curMember;
			if (bot == *curBot)
				isTeamMember = true;
		}
			

		//make sure the bot is alive and that it is not the owner
		if ((*curBot)->isAlive() && (*curBot != Raven_TargetingSystem::m_pOwner) && !isTeamMember)
		{
			double dist = Vec2DDistanceSq((*curBot)->Pos(), m_pOwner->Pos());

			if (dist < ClosestDistSoFar)
			{
				ClosestDistSoFar = dist;
				Raven_TargetingSystem::m_pCurrentTarget = *curBot;
			}
		}
	}
}
