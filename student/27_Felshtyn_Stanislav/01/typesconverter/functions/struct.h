#pragma once
struct point
{
	float x;
	float y;
};

struct ray
{
	struct point a0;
	float angle;
};
struct straigt1
{
	struct point a;
	struct point b;
};
struct straigt2
{
	float a;
	float b;			// y = ax+b
};
struct triangle
{
	struct point a;
	struct point b;
	struct point c;
};
struct rectangle
{
	struct point topleft;
	struct point rightdown;
};
struct circle
{
	struct point centre;
	float radius;
};

