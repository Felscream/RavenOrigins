#include "TeamBot.h"
#include "Raven_TargetingSystemTeam.h"
#include "Raven_Bot.h"
#include "misc/Cgdi.h"
#include "misc/utils.h"
#include "lua/Raven_Scriptor.h"
#include "Raven_Game.h"
#include "Raven_UserOptions.h"
#include "Raven_WeaponSystem.h"




TeamBot::TeamBot(Raven_Game* world, Vector2D pos, Team* t) : Raven_Bot(world, pos)
{
	team = t;
	Raven_Bot::m_pTargSys = new Raven_TargetingSystemTeam(this);
}


TeamBot::~TeamBot()
{
	delete Raven_Bot::m_pTargSys;
}


void TeamBot::Render()
{
	m_iNumUpdatesHitPersistant--;


	if (isDead() || isSpawning()) return;

	gdi->BluePen();

	m_vecBotVBTrans = WorldTransform(m_vecBotVB,
		Pos(),
		Facing(),
		Facing().Perp(),
		Scale());

	gdi->ClosedShape(m_vecBotVBTrans);

	gdi->BrownBrush();
	gdi->Circle(Pos(), 6.0 * Scale().x);

	m_pWeaponSys->RenderCurrentWeapon();

	if (m_bHit)
	{
		gdi->ThickRedPen();
		gdi->HollowBrush();
		gdi->Circle(m_vPosition, BRadius() + 1);

		if (m_iNumUpdatesHitPersistant <= 0)
		{
			m_bHit = false;
		}
	}

	gdi->TransparentText();
	switch (team->GetColor()) {
	case 0: gdi->TextColor(255, 0, 0); break;
	case 1: gdi->TextColor(0, 255, 0); break;
	case 2: gdi->TextColor(0, 0, 255); break;
	default: gdi->TextColor(0, 0, 0); break;
	}
	

	if (UserOptions->m_bShowBotIDs)
	{
		gdi->TextAtPos(Pos().x - 10, Pos().y - 20, ttos(ID()));
	}

	if (UserOptions->m_bShowBotHealth)
	{
		gdi->TextAtPos(Pos().x - 40, Pos().y - 5, "H:" + ttos(Health()));
	}

	if (UserOptions->m_bShowScore)
	{
		gdi->TextAtPos(Pos().x - 40, Pos().y + 10, "Scr:" + ttos(Score()));
	}
}