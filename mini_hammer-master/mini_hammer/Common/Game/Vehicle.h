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

	// 获取World
	GameWorld* const			GetWorld()const{return m_pWorld;}

private:
	// 逻辑世界
	GameWorld*			m_pWorld;

	// 行为树分频器
	Regulator*          m_pGoalArbitrationRegulator;
};
#endif

