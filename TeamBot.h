#pragma once

#include "Raven_Bot.h"
#include "Raven_Game.h"
#include "2D\Vector2D.h"
#include "Team.h"

class Team;

class TeamBot : public Raven_Bot
{
protected:
	Team* team;

public:
	TeamBot(Raven_Game* world, Vector2D pos, Team* t);
	~TeamBot();

	Team* GetTeam() { return team; }
	void Render();
};
