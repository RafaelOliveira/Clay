#include "rectangle_ext.h"

Rectangle _testRect;

void SetRectangle(Rectangle *rect, float x, float y, float width, float height)
{
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
}

void SetPosRectangle(Rectangle *rect, float x, float y)
{
	rect->x = x;
	rect->y = y;
}

bool CollisionRectangles(Rectangle *rect, Rectangle *otherRect)
{
	bool a;
	bool b;

	if (rect->x < otherRect->x)
		a = otherRect->x < rect->x + rect->width;
	else
		a = rect->x < otherRect->x + otherRect->width;

	if (rect->y < otherRect->y)
		b = otherRect->y < rect->y + rect->height;
	else
		b = rect->y < otherRect->y + otherRect->height;

	return a && b;
}

bool CollisionRectanglesProjected(Rectangle *rect, float tx, float ty, Rectangle *otherRect, float rx, float ry)
{
	bool a;
	bool b;

	if (rect->x + tx < otherRect->x + rx)
		a = otherRect->x + rx < rect->x + tx + rect->width;
	else
		a = rect->x + tx < otherRect->x + rx + otherRect->width;

	if (rect->y + ty < otherRect->y + ry)
		b = otherRect->y + ry < rect->y + ty + rect->height;
	else
		b = rect->y + ty < otherRect->y + ry + otherRect->height;

	return a && b;
}

bool PointInsideRectangle(Rectangle *rect, float px, float py)
{
	if (px > rect->x && px < (rect->x + rect->width) && py > rect->y && py < (rect->y + rect->height))
		return true;
	else
		return false;
}

bool RectangleInsideRectangle(Rectangle *rect, Rectangle *otherRect)
{
	if (otherRect->width <= rect->width && otherRect->height <= rect->height
		&& ((otherRect->x == rect->x && otherRect->y == rect->y) || (otherRect->x > rect->x && (otherRect->x + otherRect->width) < (rect->x + rect->width) && (otherRect->y + otherRect->height) < (rect->y + rect->height))
	))
		return true;
	else
		return false;
}

void IntersectionRectangles(Rectangle *rect, Rectangle *otherRect, Rectangle *interRect)
{
	float nx = 0;
	float ny = 0;
	float nw = 0;
	float nh = 0;

	if (rect->x < otherRect->x)
	{
		nx = otherRect->x;
		nw = (rect->x + rect->width) - otherRect->x;
	}
	else
	{
		nx = rect->x;

		if ((rect->x + rect->width) < (otherRect->x + otherRect->width))
			nw = rect->width;
		else
			nw = (otherRect->x + otherRect->width) - rect->x;
	}

	if (rect->y < otherRect->y)
	{
		ny = otherRect->y;
		nh = (rect->y + rect->height) - otherRect->y;
	}
	else
	{
		ny = rect->y;

		if ((rect->y + rect->height) < (otherRect->y + otherRect->height))
			nh = rect->height;
		else
			nh = (otherRect->y + otherRect->height) - rect->y;
	}

	SetRectangle(interRect, nx, ny, nw, nh);    
}

bool SeparateRectangles(Rectangle *rect, Rectangle *otherRect)
{
	if (CollisionRectangles(rect, otherRect))
	{
		IntersectionRectangles(rect, otherRect, &_testRect);

		// collided horizontally
		if (_testRect.height > _testRect.width)
		{
			// collided from the right
			if ((rect->x + rect->width) > otherRect->x && (rect->x + rect->width) < (otherRect->x + otherRect->width))
				rect->x = otherRect->x - rect->width;
			// collided from the left
			else
				rect->x = otherRect->x + otherRect->width;
		}
		// collided vertically
		else
		{
			// collided from the top
			if ((rect->y + rect->height) > otherRect->y && (rect->y + rect->height) < (otherRect->y + otherRect->height))
				rect->y = otherRect->y - rect->height;
			// collided from the bottom
			else
				rect->y = otherRect->y + otherRect->height;
		}

		return true;
	}
	else
		return false;
}
