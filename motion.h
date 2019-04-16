#ifndef MOTION_H
#define MOTION_H

#include "raylib.h"

class Motion
{
	public:

		Vector2 velocity;
		Vector2 maxVelocity;
		Vector2 acceleration;
		Vector2 drag;

		Motion();
		void Update();

	private:

		float ComputeVelocity(float compVelocity, float compAcceleration, float compDrag, float compMaxVelocity);
};

#endif // MOTION_H
