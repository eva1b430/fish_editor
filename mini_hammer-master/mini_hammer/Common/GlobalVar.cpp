#include "GlobalVar.h"

GlobalVar::GlobalVar()
	: m_pGameWorld(NULL)
{

}

GlobalVar::~GlobalVar()
{

}

GlobalVar& GlobalVar::instance()
{
	static GlobalVar inst;
	return inst;
}

GameWorld* GlobalVar::GetGameWorld()
{
	return m_pGameWorld;
}

void GlobalVar::SetGameWorld(GameWorld* pGameWorld)
{
	m_pGameWorld = pGameWorld;
}
