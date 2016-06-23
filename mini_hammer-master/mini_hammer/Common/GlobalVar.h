#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include "cocos2d.h"
#include "GameWorld.h"

using namespace cocos2d;

class GlobalVar
{
public:	
	GlobalVar();
	virtual ~GlobalVar();
	static GlobalVar& instance();

	GameWorld* GetGameWorld();
	void SetGameWorld(GameWorld* pGameWorld);

public:
	GameWorld*	m_pGameWorld;
};

#endif /*GLOBAL_VAR*/