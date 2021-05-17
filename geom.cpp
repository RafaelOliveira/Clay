#include "geom.h"

vector<Vector2> GetPointsLine(float x0, float y0, float x1, float y1, int segments)
{        
	vector<Vector2> points;
	float distance = sqrt( ((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)) );
	Vector2 vec { x1 - x0, y1 - y0 };

	if (segments == 0)
		segments = int(distance / 10);
	
	//vec.length = int(distance / segments);

	for (int i = 0; i < segments; i++)
	{
		points.push_back(Vector2 { x0, y0 });
		x0 += vec.x;
		y0 += vec.y;
	}

	return points;
}

vector<Vector2> GetPointsEllipse(float cx, float cy, float rx, float ry, int segments)
{
	vector<Vector2> points;

	if (segments <= 0)
		segments = floor(10 * sqrt(rx));
	
	float x;
	float y;
	
	float angle = 0.0;

	// go through all angles from 0 to 2 * PI radians
	while (angle < (2 * PI))
	{			
		// calculate x, y from a vector with known length and angle
		x = rx * cos(angle);
		y = ry * sin(angle);

		points.push_back(Vector2 { x + cx, y + cy });
		angle += 2 * (PI / segments);
	}
	
	points.push_back(Vector2 { rx + cx, cy });

	return points;
}

vector<Vector2> GetPointsCubicBezier(float x[4], float y[4], int segments)
{
	vector<Vector2> points;

	float t;
	
	Vector2 p = CalculateCubicBezierPoint(0, x, y);
	points.push_back(Vector2 { p.x, p.y });
	
	for (int i = 1; i < (segments + 1); i++)
	{
		t = i / segments;
		p = CalculateCubicBezierPoint(t, x, y);
		points.push_back(Vector2 {p.x, p.y });
	}

	return points;
}

vector<Vector2> GetPointsCubicBezierPath(vector<float> x, vector<float> y, int segments)
{
	vector<Vector2> points;

	unsigned int i = 0;
	float  t;
	Vector2 p;

	while (i < x.size() - 3)
	{
		if (i == 0)
		{
			float xArray[4] = { x[i], x[i + 1], x[i + 2], x[i + 3] };
			float yArray[4] = { y[i], y[i + 1], y[i + 2], y[i + 3] };

			p = CalculateCubicBezierPoint(0, xArray, yArray);
			points.push_back(Vector2 { p.x, p.y });
		}


		for (int j = 1; j < (segments + 1); j++)
		{
			t = j / segments;

			float xArray[4] = { x[i], x[i + 1], x[i + 2], x[i + 3] };
			float yArray[4] = { y[i], y[i + 1], y[i + 2], y[i + 3] };

			p = CalculateCubicBezierPoint(t, xArray, yArray);
			points.push_back(Vector2 { p.x, p.y });
		}
		
		i += 3;
	}

	return points;
}

Vector2 CalculateCubicBezierPoint(float t, float x[4], float y[4])
{
	float u = 1 - t;
	float tt = t * t;
	float uu = u * u;
	float uuu = uu * u;
	float ttt = tt * t;
		
	// first term
	Vector2 p { uuu * x[0], uuu * y[0] };
		
	// second term				
	p.x += 3 * uu * t * x[1];
	p.y += 3 * uu * t * y[1];
		
	// third term				
	p.x += 3 * u * tt * x[2];
	p.y += 3 * u * tt * y[2];		
		
	// fourth term				
	p.x += ttt * x[3];
	p.y += ttt * y[3];

	return p;
}
