#ifndef TRIGGER_H
#define TRIGGER_H
#include "BaseEntity.h"
#include "Vehicle.h"

// �ṩһ����򵥵�����Բ�Σ�
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

// ����������
class Trigger/* : public BaseEntity*/
{
public:
	Trigger(void)
	{

	}

	~Trigger(void)
	{

	}

	// ������WE֧��ͼ�λ��༭������
	virtual void  Try(Vehicle* pVehicle) = 0;

	// �������ԣ���������ò��ϣ�
	virtual void  Update()
	{

	}

};

// ���򴥷�����������������һ�֣�
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
	// ��Ӧ������
	TriggerRegionCircle* m_pRegion;
};

#endif /*TRIGGER_H*/