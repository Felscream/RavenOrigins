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
	TeamBot *tb = (TeamBot*)Raven_TargetingSystem::m_pOwner;
	Raven_TargetingSystem::m_pCurrentTarget = tb->GetTeam()->GetLeader()->GetTargetBot();
}