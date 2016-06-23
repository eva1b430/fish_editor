#ifndef VEHICLE_H
#define VEHICLE_H
#include "MovingEntity.h"

class GameWorld;
class Regulator;
class Vehicle : public MovingEntity
{
public:
	Vehicle(GameWorld* world, CCPoint position);
	virtual ~Vehicle(void);

	// ��ȡWorld
	GameWorld* const			GetWorld()const{return m_pWorld;}

private:
	// �߼�����
	GameWorld*			m_pWorld;

	// ��Ϊ����Ƶ��
	Regulator*          m_pGoalArbitrationRegulator;
};
#endif

