//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

// Triangle rendering, if any

#include "hud.h"
#include "cl_util.h"

// Triangle rendering apis are in gEngfuncs.pTriAPI

#include "const.h"
#include "entity_state.h"
#include "cl_entity.h"
#include "triangleapi.h"
#include "Exports.h"

#include "particleman.h"
#include "tri.h"
extern IParticleMan *g_pParticleMan;

/*
=================
HUD_DrawNormalTriangles

Non-transparent triangles-- add them here
=================
*/
void CL_DLLEXPORT HUD_DrawNormalTriangles( void )
{
//	RecClDrawNormalTriangles();

	gHUD.m_Spectator.DrawOverview();
}

#if defined( _TFC )
void RunEventList( void );
#endif

/*
=================
HUD_DrawTransparentTriangles

Render any triangles with transparent rendermode needs here
=================
*/
void CL_DLLEXPORT HUD_DrawTransparentTriangles( void )
{
//	RecClDrawTransparentTriangles();

#if defined( _TFC )
	RunEventList();
#endif

	gHUD.m_Glow.DrawGlow();
	if ( g_pParticleMan )
		 g_pParticleMan->Update();
}
//
// Code adapted from tutorial written by Toni Sergi, aka - twlomega.
//
// http://twhl.info/articulator.php?art=114
//

/*
=================
HUD_DrawOrthoTriangles
Orthogonal Triangles -- (relative to resolution,
smackdab on the screen) add them here
=================
*/
void HUD_DrawOrthoTriangles(void)
{
	gHUD.m_Health.DrawPain2();
	gHUD.m_DeathVision.DrawDeathVision();
	gHUD.m_Cinematic.DrawCinematic();
}
