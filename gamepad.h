#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "raylib.h"

class Gamepad
{
	public:

		int id;

		void Init(int id);
		bool IsActive();
		void AxisBegin();
		void AxisEnd();
		bool IsAxisPressed(int dir);
		bool IsAxisDown(int dir);
		bool IsBtnDown(int btn);
		bool IsBtnPressed(int btn);		
		
	private:

		float axisMovement[2];
		bool axisPressed[2];
		bool axisPressedBefore[2];
};

#endif