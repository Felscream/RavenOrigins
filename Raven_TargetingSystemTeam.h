#pragma once
#include "Raven_TargetingSystem.h"
#include "Raven_Bot.h"
#include "TeamBot.h"

class Raven_TargetingSystemTeam :
	public Raven_TargetingSystem
{
public:
	Raven_TargetingSystemTeam(Raven_Bot* owner);
	~Raven_TargetingSystemTeam();

	void Update();
};

