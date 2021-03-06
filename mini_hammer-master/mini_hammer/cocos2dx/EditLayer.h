#ifndef EDITLAYER_H
#define EDITLAYER_H

#include "cocos2d.h"
#include "ccTypes.h"

// �༭��
using namespace cocos2d;
#define EDIT_LAYER_ALPHA	255
class EditLayer : public cocos2d::CCLayerColor
{
public:
	enum GLPenColor
	{
		GL_Red,
		GL_Blue, 
		GL_Green,
		GL_Black,
		GL_Pink,
		GL_Grey,
		GL_Yellow,
		GL_Orange,
		GL_Purple,
		GL_Brown,   
		GL_White,
		GL_Dark_Green,
		GL_Light_Blue,
		GL_Light_Grey,
		GL_Light_Pink,
		GL_Hollow
	};
public:
	EditLayer(void)
		: m_pTriggerSprite(NULL)
	{

	}
	virtual ~EditLayer()
	{

	}

    virtual bool init();
    
    // implement the "static node()" method manually
    CREATE_FUNC(EditLayer);

	virtual void onEnter();
	virtual void onExit();
	virtual void update(float delta);

	virtual void draw();

	void updateEditMarkPosition(CCPoint pos);

protected:
	// �л���ɫ
	void ChangeColor(GLPenColor color);

	// ����դ��
	void DrawGrid();

private:
	ccColor4B	m_pTerrainColor;
	CCSprite*	m_pTriggerSprite;
};

#endif // EDITLAYER_H
