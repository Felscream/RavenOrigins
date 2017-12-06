#pragma once
#include "TeamBot.h"
#include "Raven_Bot.h"
#include "Team.h"

class Team;

class TeamBotLeader : public Raven_Bot
{
private:
	Team* team;

public:
	TeamBotLeader(Raven_Game* world, Vector2D pos, Team* t);
	~TeamBotLeader();

	Team* GetTeam() { return team; }
	void Render();
};

