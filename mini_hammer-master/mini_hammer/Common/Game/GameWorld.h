#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "cocos2d.h"
#include <list>

using namespace std;
using namespace cocos2d;

class GameWorld
{
public:
	GameWorld(void);
	~GameWorld(void);

	void Update(double time_elapsed);
	void bindToCCLayer(CCLayer* pLayer);

private:
	// °ó¶¨µÄUIÄ£¿é
	CCLayer*			m_pUILayer;
};
#endif

