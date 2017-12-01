#pragma once
#include "Raven_TargetingSystem.h"

class Raven_TargetingSystemLeader : public Raven_TargetingSystem
{
public:
	Raven_TargetingSystemLeader(Raven_Bot* owner);
	~Raven_TargetingSystemLeader();

	void Update();
};

