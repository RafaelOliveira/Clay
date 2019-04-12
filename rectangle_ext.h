#ifndef RECTANGLE_EXT_H
#define RECTANGLE_EXT_H

#include "raylib.h"

void SetRectangle(Rectangle *rect, float x, float y, float width, float height);
void SetPosRectangle(Rectangle *rect, float x, float y);
bool CollisionRectangles(Rectangle *rect, Rectangle *otherRect);
bool CollisionRectanglesProjected(Rectangle *rect, float tx, float ty, Rectangle *otherRect, float rx, float ry);
bool PointInsideRectangle(Rectangle *rect, float px, float py);
bool RectangleInsideRectangle(Rectangle *rect, Rectangle *otherRect);
void IntersectionRectangles(Rectangle *rect, Rectangle *otherRect, Rectangle *interRect);
bool SeparateRectangles(Rectangle *rect, Rectangle *otherRect);

#endif
