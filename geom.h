#ifndef GEOM_H
#define GEOM_H

#include <math.h>
#include <vector>
#include "raylib.h"
#include "math_ext.h"

using std::vector;

vector<Vector2> GetPointsLine(float x0, float y0, float x1, float y1, int segments = 0);
vector<Vector2> GetPointsEllipse(float cx, float cy, float rx, float ry, int segments = 0);
vector<Vector2> GetPointsCubicBezier(float x[4], float y[4], int segments = 20);
vector<Vector2> GetPointsCubicBezierPath(vector<float> x, vector<float> y, int segments = 20);
Vector2 CalculateCubicBezierPoint(float t, float x[4], float y[4]);

#endif