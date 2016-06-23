#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H
#include "BaseEntity.h"

class MovingEntity : public BaseEntity
{
public:
	MovingEntity(CCPoint position)
		: BaseEntity(emBaseEntity_Type_Default, position)
	{
		
	}

	virtual ~MovingEntity(void);

protected:
	
};
#endif

