#pragma once

#include "TeamBot.h"
#include "TeamBotLeader.h"
#include "Raven_Game.h"

#include <list>

using namespace std;

class TeamBotLeader;
class TeamBot;

class Team
{
private:
	int name;
	list<TeamBot*> teamMembers;
	TeamBotLeader* leader;

public:
	Team();
	~Team();


	TeamBotLeader* GetLeader() { return leader; }
	void SetLeader(TeamBotLeader* l) { leader = l; }
	list<TeamBot*> GetMembers() { return teamMembers;	}
	void AddMember(TeamBot*m) { teamMembers.push_back(m); }

};

