#include "motion.h"

Motion::Motion()
{
	velocity.x = 0;
	velocity.y = 0;

	acceleration.x = 0;
	acceleration.y = 0;

	drag.x = 0;
	drag.y = 0;

	maxVelocity.x = 10000;
	maxVelocity.y = 10000;
}

void Motion::Update()
{
	velocity.x = ComputeVelocity(velocity.x, acceleration.x, drag.x, maxVelocity.x);
	velocity.y = ComputeVelocity(velocity.y, acceleration.y, drag.y, maxVelocity.y);
}

float Motion::ComputeVelocity(float compVelocity, float compAcceleration, float compDrag, float compMaxVelocity)
{
	if (compAcceleration != 0)
		compVelocity += compAcceleration;
	else if (compDrag != 0)
	{
		if (compVelocity - compDrag > 0)
		{
			compVelocity -= compDrag;
		}
		else if (compVelocity + compDrag < 0)
		{
			compVelocity += compDrag;
		}
		else
			compVelocity = 0;
	}

	if ((compVelocity != 0) && (compMaxVelocity != 0))
	{
		if (compVelocity > compMaxVelocity)
			compVelocity = compMaxVelocity;
		else if (compVelocity < -compMaxVelocity)
			compVelocity = -compMaxVelocity;
	}

	return compVelocity;
}
