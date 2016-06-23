#include "EditLayer.h"
#include "AppMacros.h"
#include "GlobalVar.h"
#include "Vehicle.h"

using namespace cocos2d;
bool EditLayer::init()
{
	ChangeColor(GL_Grey);

    if ( !CCLayerColor::initWithColor(ccc4(0, 0, 0, 255)) )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//setTouchEnabled(false);
    
    return true;
}

void EditLayer::onEnter()
{
	CCLayerColor::onEnter();

	// 添加
	scheduleUpdate();

	// 编辑标记
	m_pTriggerSprite = CCSprite::create();
	addChild(m_pTriggerSprite);
	m_pTriggerSprite->setOpacity(200);
	m_pTriggerSprite->setScale(2.0f);
}

void EditLayer::onExit()
{
	// 添加
	unscheduleUpdate();

	CCLayerColor::onExit();
}

void EditLayer::update(float delta)
{
	CCLayerColor::update(delta);
}

void EditLayer::draw()
{
	CCLayerColor::draw();

	DrawGrid();
}

void EditLayer::updateEditMarkPosition(CCPoint pos)
{
	if (m_pTriggerSprite)
	{
		m_pTriggerSprite->setPosition(pos);
	}
}

void EditLayer::ChangeColor(GLPenColor color)
{
	switch(color)
	{
	case GL_Red:
		{
			m_pTerrainColor = ccc4(255,0,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Blue:
		{
			m_pTerrainColor = ccc4(0,0,255,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Green:
		{
			m_pTerrainColor = ccc4(0,255,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Black:
		{
			m_pTerrainColor = ccc4(0,0,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Pink:
		{
			m_pTerrainColor = ccc4(255,200,200,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Grey:
		{
			m_pTerrainColor = ccc4(200,200,200,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Yellow:
		{
			m_pTerrainColor = ccc4(255,255,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Orange:
		{
			m_pTerrainColor = ccc4(255,170,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Purple:
		{
			m_pTerrainColor = ccc4(255,0,170,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Brown:
		{
			m_pTerrainColor = ccc4(133,90,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_White:
		{
			m_pTerrainColor = ccc4(255,255,255,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Dark_Green:
		{
			m_pTerrainColor = ccc4(0,100,0,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Light_Blue:
		{
			m_pTerrainColor = ccc4(0,255,255,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Light_Grey:
		{
			m_pTerrainColor = ccc4(200,200,200,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Light_Pink:
		{
			m_pTerrainColor = ccc4(255,230,230,EDIT_LAYER_ALPHA);
		}
		break;
	case GL_Hollow:
		{
			m_pTerrainColor = ccc4(255,255,255,EDIT_LAYER_ALPHA);
		}
		break;

	}

	ccColor4F color2 = ccc4FFromccc4B(m_pTerrainColor);
	ccDrawColor4F(color2.r, color2.g, color2.b, color2.a);
}

void EditLayer::DrawGrid()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	int nWidth = visibleSize.width;
	int nHeight = visibleSize.height;

	// 绘制网格线
	CCPoint pointCenter;
	pointCenter.x = nWidth / 2;
	pointCenter.y = nHeight / 2;
	// 半个视图的宽度
	long halfWidth = nWidth / 2;
	long halfHeight = nHeight / 2;

	// 绘制垂直网格
	ChangeColor(GL_White);
	glLineWidth(0.8f);

	// 单位网格投影在屏幕上的像素数
	float gpix = 40;

	int nHalfCount = halfWidth / gpix;
	for (int j = -nHalfCount; j <= nHalfCount; j++)
	{
		ccDrawLine(convertToNodeSpace(CCPointMake(pointCenter.x + j * gpix, 0)), 
			convertToNodeSpace(CCPointMake(pointCenter.x + j * gpix, nHeight)));
	}

	// 绘制水平网格
	nHalfCount = halfHeight / gpix;
	for (int j = -nHalfCount; j <= nHalfCount; j++)
	{
		ccDrawLine(convertToNodeSpace(CCPointMake(0, pointCenter.y + j * gpix)), 
			convertToNodeSpace(CCPointMake(nWidth, pointCenter.y + j * gpix)));
	}
}
