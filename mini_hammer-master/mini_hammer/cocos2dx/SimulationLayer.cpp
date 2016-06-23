#include "SimulationLayer.h"
#include "AppMacros.h"
#include "GlobalVar.h"
#include "Vehicle.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool SimulationLayer::init()
{
    if ( !/*CCLayerColor::init()*/CCLayerColor::initWithColor(ccc4(173, 192, 218, 255)) )
    {
        return false;
    }

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

	// Ìí¼Ó±³¾°
	m_pBackGround = CCSprite::create("media/fish_base/Bg/bj02.jpg");
	addChild(m_pBackGround);
	m_pBackGround->setPosition(CCPointMake(winSize.width / 2, winSize.height / 2));

	m_pBackGround->setOpacity(120);
    
    return true;
}

void SimulationLayer::onEnter()
{
	CCLayerColor::onEnter();

	// Ìí¼Ó
	scheduleUpdate();
}

void SimulationLayer::onExit()
{
	// Ìí¼Ó
	unscheduleUpdate();

	CCLayerColor::onExit();
}

void SimulationLayer::update(float delta)
{
	CCLayerColor::update(delta);

	if (m_pGameWorld)
	{
		m_pGameWorld->Update(delta);
	}
}

void SimulationLayer::draw()
{
	CCLayerColor::draw();
}

void SimulationLayer::onEnterTransitionDidFinish()
{
	// Á´½ÓÂß¼­²ã
	m_pGameWorld = GlobalVar::instance().GetGameWorld();
	m_pGameWorld->bindToCCLayer(this);
}

bool SimulationLayer::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	return true;
}

void SimulationLayer::ccTouchMoved( CCTouch *pTouch, CCEvent *pEvent )
{

}

void SimulationLayer::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{
	CCPoint touchpoint = pTouch->getLocation();
	
	//Vehicle* pOwn = NULL;
	//pOwn = GlobalVar::instance().GetGameWorld()->getOwn();
	//if (pOwn)
	//{
	//	pOwn->GetSteering()->SetTarget(GlobalVar::instance().CocosPosToHammerPos(touchpoint));
	//}
}
