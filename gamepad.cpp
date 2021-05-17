#include "gamepad.h"

void Gamepad::Init(int id)
{
	this->id = id;
}

bool Gamepad::IsActive()
{
	return IsGamepadAvailable(id);
}

void Gamepad::AxisBegin()
{
	for (int i = 0; i < 2; ++i)
	{
		axisMovement[i] = GetGamepadAxisMovement(id, i);

		if (axisMovement[i] == 1 || axisMovement[i] == -1)
		{
			if (!axisPressedBefore[i])				
				axisPressed[i] = true;						
		}
		else if (axisMovement[i] < 1 && axisMovement[i] > -1)
		{
			axisPressed[i] = false;
			axisPressedBefore[i] = false;
		}		
	}
}

void Gamepad::AxisEnd()
{
	for (int i = 0; i < 2; ++i)
	{
		if (axisPressed[i] && !axisPressedBefore[i])
		{
			axisPressedBefore[i] = true;
			axisPressed[i] = false;
		}
	}
}

bool Gamepad::IsAxisPressed(int dir)
{
	// up, down: axis 1
	// left, right: axis 0

	switch(dir)
	{
		case KEY_UP:
			if (axisPressed[1] && !axisPressedBefore[1] && axisMovement[1] == -1)
				return true;
			break;

		case KEY_DOWN:
			if (axisPressed[1] && !axisPressedBefore[1] && axisMovement[1] == 1)
				return true;
			break;

		case KEY_LEFT:
			if (axisPressed[0] && !axisPressedBefore[0] && axisMovement[0] == -1)
				return true;
			break;

		case KEY_RIGHT:
			if (axisPressed[0] && !axisPressedBefore[0] && axisMovement[0] == 1)
				return true;
			break;
	}

	return false;	
}

bool Gamepad::IsAxisDown(int dir)
{
	// up, down: axis 1
	// left, right: axis 0

	switch(dir)
	{
		case KEY_UP:
			if (GetGamepadAxisMovement(id, 1) == -1)
				return true;
			break;

		case KEY_DOWN:
			if (GetGamepadAxisMovement(id, 1) == 1)
				return true;
			break;

		case KEY_LEFT:
			if (GetGamepadAxisMovement(id, 0) == -1)
				return true;
			break;

		case KEY_RIGHT:
			if (GetGamepadAxisMovement(id, 0) == 1)
				return true;
			break;
	}

	return false;
}

bool Gamepad::IsBtnDown(int btn)
{
	return IsGamepadButtonDown(id, btn);
}

bool Gamepad::IsBtnPressed(int btn)
{
	return IsGamepadButtonPressed(id, btn);
}