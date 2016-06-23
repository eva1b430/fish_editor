#ifndef BASEENTITY_H
#define BASEENTITY_H
#include "cocos2d.h"

using namespace cocos2d;
class BaseEntity : public CCSprite
{
public:
	enum BaseEntity_Type
	{
		emBaseEntity_Type_Default			= -1,
		emBaseEntity_Type_Wall				= 0,
		emBaseEntity_Type_Bot				= 1,
		emBaseEntity_Type_Unused			= 2,
		emBaseEntity_Type_Waypoint			= 3,
		emBaseEntity_Type_Health			= 4,
		emBaseEntity_Type_Spawn_Point		= 5,

		emBaseEntity_Type_Rail_Gun			= 6,
		emBaseEntity_Type_Rocket_Launcher	= 7,
		emBaseEntity_Type_Shotgun			= 8,
		emBaseEntity_Type_Blaster			= 9,

		emBaseEntity_Type_Obstacle			= 10,
		emBaseEntity_Type_Sliding_Door		= 11,
		emBaseEntity_Type_Door_Trigger		= 12
	};

public:
	// ���캯��
	BaseEntity(BaseEntity_Type entity_type, CCPoint pos)
		: m_nID(NextValidID())
		, m_vPos(pos)
	{}

	virtual ~BaseEntity(void);

	virtual void onEnter()
	{
		CCSprite::onEnter();

		// ���
		scheduleUpdate();
	}
	virtual void onExit()
	{
		// ���
		unscheduleUpdate();

		CCSprite::onExit();
	}

	// ��ȡID
	int          GetID()const{return m_nID;}

	// Type����
	BaseEntity_Type			GetEntityType()const{return m_emEntityType;}
	void					SetEntityType(BaseEntity_Type new_type){m_emEntityType = new_type;}

private:
	// BaseEntity��ID
	int					m_nID;

	// ����
	BaseEntity_Type		m_emEntityType;

	int NextValidID()
	{
		static int NextID = 0;
		return NextID++;
	}

protected:
	// λ��
	CCPoint			m_vPos;
};
#endif // BASEENTITY_H

