#include "EntityList.h"
#include "GUIApplication.h"
typedef unsigned char byte;
typedef int DWORD;

class Game
{
	byte gap0[12];
	GUIApplication* m_pGUIApplication;
	int* Verlet$$ParticleSystem;
	DWORD* int14;
	byte gap18[2516];
	EntityList Person_Entitylist;
	EntityList Fighter_Entitylist;
	EntityList StaticObject_Entitylist;
	byte gapA94[405];
	int* World_c2c;
	int* Fog_c30;
	byte gapC34[228];
	int* FighterInputHandler_d18;
	__declspec(align(8)) int AiSystem_d20;
	int* Interaction_d24;
	int* GameInput_d28;
	byte gapD2C;
	byte debugmode_D2D;
	byte gapD2E[46];
	int* Visual$$Hud;
	byte gapD60[32];
	int* WorldBlock;
	byte gapD84[1212];
	int* TiXmlBase;
	byte gap1244[232];
	int* UserStats;
	byte gap1330[20];
	int* UserStats_;
	byte gap1348[332];
	int* Crosshair;
	byte gap1498[16];
	int* ChatLog;
	int* Visual$$EffectSystem;
	int* Visual$$Manager;
	byte gap14B4[24];
	int Aural$$Manager;
	byte gap14D0[72];
	int* WorldSituation;
	byte gap151C[52];
	byte no_simulation_1550;
	byte gap1551[147];
	int* State;
	byte gap15E8[68];
	int* ProfileManager;
	byte gap1630[328];
	int* Ogre$$SharedPtr_of_Ogre$$ScriptToken;
	byte gap177C[2276];
	byte lag_mode_2060;
	byte unknown2[443];
	byte antihack_221c;

	GUIApplication* get_GUIApplication()
	{
		return this->m_pGUIApplication;
	}

	EntityList get_Person_Entitylist()
	{
		return this->Person_Entitylist;
	}
	EntityList get_Fighter_Entitylist()
	{
		return this->Fighter_Entitylist;
	}
	EntityList get_StaticObject_Entitylist()
	{
		return this->StaticObject_Entitylist;
	}
};