#ifndef MATH_EXT_H
#define MATH_EXT_H

#include <math.h>
#include "raylib.h"

//float PI = 3.141592653589793;

float Distance(float x1, float y1, float x2, float y2);
//float Lerp(float a, float b, float t);
float Scale(float value, float min, float max, float min2, float max2);
float Radian(float value);
float Degree(float value);
int PointInside(float px, float py, float x, float y, int w, int h);
int RectCollision(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2);
//float Clamp(float value, float min, float max);

#endif
