#define _USE_MATH_DEFINES
#include "shape.h"
#include <cmath>
#include <iostream>



Shape::Shape(int _x1, int _y1, int _x2, int _y2)
{
	type = static_cast<int> (nameOfShapes::line);
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	square = 0.;
	volume = 0.;
}

Shape::Shape(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
	type = static_cast<int> (nameOfShapes::sqr);
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	x3 = _x3; y3 = _y3;
	x4 = _x4; y4 = _y4;
	square = pow((x1 - x2), 2) + pow((y1 - y2), 2);
	volume = 0.;
}

Shape::Shape(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	type = static_cast<int> (nameOfShapes::cube);
	x1 = _x1; y1 = _y1; z1 = _z1;
	x2 = _x2; y2 = _y2; z2 = _z2;
	x3 = _x3; y3 = _y3; z3 = _z3;
	x4 = _x4; y4 = _y4; z4 = _z4;
	x5 = _x5; y5 = _y5; z5 = _z5;
	x6 = _x6; y6 = _y6; z6 = _z6;
	x7 = _x7; y7 = _y7; z7 = _z7;
	x8 = _x8; y8 = _y8; z8 = _z8;
	square = 6 * (pow((x1 - x2), 2) + pow((y1 - y2), 2));
	volume = 2 * (pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

Shape::Shape(int _x1, int _y1, double R)
{
	type = static_cast<int> (nameOfShapes::circle);
	x1 = _x1; y1 = _y1;
	radius = R;
	square = M_PI * R * R;
	volume = 0.;
}

Shape::Shape(int _x1, int _y1, double R, double H)
{
	type = static_cast<int> (nameOfShapes::cylinder);
	x1 = _x1; y1 = _y1;
	radius = R;
	height = H;
	square = 2 * M_PI * R * (R + height);
	volume = M_PI * R * R * height;
}

int Shape::getType() const
{
	return type;
}

double Shape::getVolume() const
{
	return volume;
}

double Shape::getSquare() const
{
	return square;
}

double Shape::getHeight() const
{
	return height;
}

double Shape::getRadius() const
{
	return radius;
}

void Shape::shiftLine(int m, int n)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
}

void Shape::shiftSqr(int m, int n)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	x3 += m; y3 += n;
	x4 += m; y4 += n;
}

void Shape::shiftCube(int m, int n, int k)
{
		x1 += m; y1 += n; z1 += k;
		x2 += m; y2 += n; z2 += k;
		x3 += m; y3 += n; z3 += k;
		x4 += m; y4 += n; z4 += k;
		x5 += m; y5 += n; z5 += k;
		x6 += m; y6 += n; z6 += k;
		x7 += m; y7 += n; z7 += k;
		x8 += m; y8 += n; z8 += k;
}

void Shape::scaleXLine(int a)
{
	x1 *= a;
	x2 *= a;	
}

void Shape::scaleXSqr(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
}

void Shape::scaleXCube(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
	x5 *= a;
	x6 *= a;
	x7 *= a;
	x8 *= a;
}

void Shape::scaleYLine(int d)
{
	y1 *= d;
	y2 *= d;
}

void Shape::scaleYSqr(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
}

void Shape::scaleYCube(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
	y5 *= d;
	y6 *= d;
	y7 *= d;
	y8 *= d;
}

void Shape::scaleZLine(int e)
{
	z1 *= e;
	z2 *= e;
}

void Shape::scaleZSqr(int e)
{
	z1 *= e;
	z2 *= e;
	z3 *= e;
	z4 *= e;
}

void Shape::scaleZCube(int e)
{
	z1 *= e;
	z2 *= e;
	z3 *= e;
	z4 *= e;
	z5 *= e;
	z6 *= e;
	z7 *= e;
	z8 *= e;
}

void Shape::scaleLine(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
}

void Shape::scaleSqr(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
	x3 /= s; y3 /= s;
	x4 /= s; y4 /= s;
}

void Shape::scaleCube(int s)
{
	x1 /= s; y1 /= s; z1 /= s;
	x2 /= s; y2 /= s; z2 /= s;
	x3 /= s; y3 /= s; z3 /= s;
	x4 /= s; y4 /= s; z4 /= s;
	x5 /= s; y5 /= s; z5 /= s;
	x6 /= s; y6 /= s; z6 /= s;
	x7 /= s; y7 /= s; z7 /= s;
	x8 /= s; y8 /= s; z8 /= s;

}

