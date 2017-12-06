#include "Raven_TargetingSystemTeam.h"
#include "Raven_Bot.h"
#include "Raven_SensoryMemory.h"


Raven_TargetingSystemTeam::Raven_TargetingSystemTeam(Raven_Bot* owner) : Raven_TargetingSystem(owner)
{
}


Raven_TargetingSystemTeam::~Raven_TargetingSystemTeam()
{
}

void Raven_TargetingSystemTeam::Update() {
	Raven_TargetingSystem::m_pCurrentTarget = 0;
	TeamBot *tb = (TeamBot*)Raven_TargetingSystem::m_pOwner;
	Raven_TargetingSystem::m_pCurrentTarget = tb->GetTeam()->GetLeader()->GetTargetBot();

	if (!isTargetShootable()) {
		bool isTeamMember;
		double ClosestDistSoFar = MaxDouble;
		TeamBot* owner = (TeamBot*)Raven_TargetingSystem::m_pOwner;		
		Team* team = owner->GetTeam();
		Raven_Bot* leader = (Raven_Bot*)team->GetLeader();
		std::list<TeamBot*> members = team->GetMembers();
		std::list<TeamBot*>::iterator curMember = members.begin();

		//grab a list of all the opponents the owner can sense
		std::list<Raven_Bot*> SensedBots;
		SensedBots = Raven_TargetingSystem::m_pOwner->GetSensoryMem()->GetListOfRecentlySensedOpponents();


		
		std::list<Raven_Bot*>::const_iterator curBot = SensedBots.begin();
		for (curBot; curBot != SensedBots.end(); ++curBot)
		{
			isTeamMember = false;

			//Check if opponent is not a team member
			for (curMember; curMember != members.end(); curMember++) {
				Raven_Bot* bot = (Raven_Bot*)*curMember;
				if (bot == *curBot)
					isTeamMember = true;
			}

			if (*curBot == leader)
				isTeamMember = true;


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
}