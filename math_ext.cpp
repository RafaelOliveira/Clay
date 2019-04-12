#include "math_ext.h"

float Distance(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

/*float Lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}*/

float Scale(float value, float min, float max, float min2, float max2)
{
	return min2 + ((value - min) / (max - min)) * (max2 - min2);
}

float Radian(float value)
{
	return value * (PI / 180);
}

float Degree(float value)
{
	return value * (180 / PI);
}

int PointInside(float px, float py, float x, float y, int w, int h)
{
    if (px > x && px < (x + w) && py > y && py < (y + h))
        return 1;
    else
        return 0;
}

int RectCollision(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2)
{
    if (x1 + w1 > x2 &&
        y1 + h1 > y2 &&
        x1 < x2 + w2 &&
        y1 < y2 + h2)
        return 1;
    else
        return 0;
}

/*float Clamp(float value, float min, float max)
{
    if (max > min)
    {
        if (value < min) return min;
        else if (value > max) return max;
        else return value;
    }
    else
    {
        // Min/max swapped
        if (value < max) return max;
        else if (value > min) return min;
        else return value;
    }

    return 0;
}*/
