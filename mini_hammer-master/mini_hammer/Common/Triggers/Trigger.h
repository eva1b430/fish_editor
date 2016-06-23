#ifndef TRIGGER_H
#define TRIGGER_H
#include "BaseEntity.h"
#include "Vehicle.h"

// 提供一种最简单的区域（圆形）
class TriggerRegionCircle
{
private:
	CCPoint		m_vPosCenter;
	double		m_dRadius;

public:

	TriggerRegionCircle(CCPoint pos, 
						double radius)
						: m_vPosCenter(pos)
						, m_dRadius(radius)
	{

	}

	bool isTouching(CCPoint pos, double EntityRadius)const
	{
		//return Vec2DDistanceSq(m_vPosCenter, pos) < (EntityRadius + m_dRadius)*(EntityRadius + m_dRadius);
		return false;
	}
};

// 触发器基类
class Trigger/* : public BaseEntity*/
{
public:
	Trigger(void)
	{

	}

	~Trigger(void)
	{

	}

	// 条件（WE支持图形化编辑能力）
	virtual void  Try(Vehicle* pVehicle) = 0;

	// 条件测试（绝大多数用不上）
	virtual void  Update()
	{

	}

};

// 区域触发器（条件触发器的一种）
class RegionTrigger : public Trigger
{
public:
	RegionTrigger( CCPoint pos, 
				   double radius )
				   : m_pRegion(new TriggerRegionCircle(pos, radius))
	{

	}
	~RegionTrigger(void)
	{
		if (m_pRegion)
		{
			delete m_pRegion;
			m_pRegion = NULL;
		}
	}

protected:
	// 对应的区域
	TriggerRegionCircle* m_pRegion;
};

#endif /*TRIGGER_H*/