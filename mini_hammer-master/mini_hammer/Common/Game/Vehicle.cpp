#include "Vehicle.h"
#include "Regulator.h"
#include "GameWorld.h"

Vehicle::Vehicle(GameWorld* world, CCPoint position)
		: MovingEntity(position)
		, m_pWorld(world)
{
	m_pGoalArbitrationRegulator = new Regulator(4.0f);
}

Vehicle::~Vehicle(void)
{
	if (m_pGoalArbitrationRegulator)
	{
		delete m_pGoalArbitrationRegulator;
		m_pGoalArbitrationRegulator = NULL;
	}
}
