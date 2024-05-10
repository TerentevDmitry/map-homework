#define _USE_MATH_DEFINES
#include "shape.h"
#include <cmath>
#include <iostream>



Shape::Shape(int _x1, int _y1, int _x2, int _y2)
{
	type = static_cast<int> (nameOfShapes::line);
	cos.x1 = _x1; cos.y1 = _y1;
	cos.x2 = _x2; cos.y2 = _y2;
	square = 0.;
	volume = 0.;
}

Shape::Shape(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
	type = static_cast<int> (nameOfShapes::sqr);
	cos.x1 = _x1; cos.y1 = _y1;
	cos.x2 = _x2; cos.y2 = _y2;
	cos.x3 = _x3; cos.y3 = _y3;
	cos.x4 = _x4; cos.y4 = _y4;
	square = pow((cos.x1 - cos.x2), 2) + pow((cos.y1 - cos.y2), 2);
	volume = 0.;
}

Shape::Shape(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	type = static_cast<int> (nameOfShapes::cube);
	cos.x1 = _x1; cos.y1 = _y1; cos.z1 = _z1;
	cos.x2 = _x2; cos.y2 = _y2; cos.z2 = _z2;
	cos.x3 = _x3; cos.y3 = _y3; cos.z3 = _z3;
	cos.x4 = _x4; cos.y4 = _y4; cos.z4 = _z4;
	cos.x5 = _x5; cos.y5 = _y5; cos.z5 = _z5;
	cos.x6 = _x6; cos.y6 = _y6; cos.z6 = _z6;
	cos.x7 = _x7; cos.y7 = _y7; cos.z7 = _z7;
	cos.x8 = _x8; cos.y8 = _y8; cos.z8 = _z8;
	square = 6 * (pow((cos.x1 - cos.x2), 2) + pow((cos.y1 - cos.y2), 2));
	volume = 2 * (pow((cos.x1 - cos.x2), 2) + pow((cos.y1 - cos.y2), 2));
}

Shape::Shape(int _x1, int _y1, double R)
{
	type = static_cast<int> (nameOfShapes::circle);
	cos.x1 = _x1; cos.y1 = _y1;
	radius = R;
	square = M_PI * R * R;
	volume = 0.;
}

Shape::Shape(int _x1, int _y1, double R, double H)
{
	type = static_cast<int> (nameOfShapes::cylinder);
	cos.x1 = _x1; cos.y1 = _y1;
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
	cos.x1 += m; cos.y1 += n;
	cos.x2 += m; cos.y2 += n;
}

void Shape::shiftSqr(int m, int n)
{
	cos.x1 += m; cos.y1 += n;
	cos.x2 += m; cos.y2 += n;
	cos.x3 += m; cos.y3 += n;
	cos.x4 += m; cos.y4 += n;
}

void Shape::shiftCube(int m, int n, int k)
{
		cos.x1 += m; cos.y1 += n; cos.z1 += k;
		cos.x2 += m; cos.y2 += n; cos.z2 += k;
		cos.x3 += m; cos.y3 += n; cos.z3 += k;
		cos.x4 += m; cos.y4 += n; cos.z4 += k;
		cos.x5 += m; cos.y5 += n; cos.z5 += k;
		cos.x6 += m; cos.y6 += n; cos.z6 += k;
		cos.x7 += m; cos.y7 += n; cos.z7 += k;
		cos.x8 += m; cos.y8 += n; cos.z8 += k;
}

void Shape::scaleXLine(int a)
{
	cos.x1 *= a;
	cos.x2 *= a;	
}

void Shape::scaleXSqr(int a)
{
	cos.x1 *= a;
	cos.x2 *= a;
	cos.x3 *= a;
	cos.x4 *= a;
}

void Shape::scaleXCube(int a)
{
	cos.x1 *= a;
	cos.x2 *= a;
	cos.x3 *= a;
	cos.x4 *= a;
	cos.x5 *= a;
	cos.x6 *= a;
	cos.x7 *= a;
	cos.x8 *= a;
}

void Shape::scaleYLine(int d)
{
	cos.y1 *= d;
	cos.y2 *= d;
}

void Shape::scaleYSqr(int d)
{
	cos.y1 *= d;
	cos.y2 *= d;
	cos.y3 *= d;
	cos.y4 *= d;
}

void Shape::scaleYCube(int d)
{
	cos.y1 *= d;
	cos.y2 *= d;
	cos.y3 *= d;
	cos.y4 *= d;
	cos.y5 *= d;
	cos.y6 *= d;
	cos.y7 *= d;
	cos.y8 *= d;
}

void Shape::scaleZLine(int e)
{
	cos.z1 *= e;
	cos.z2 *= e;
}

void Shape::scaleZSqr(int e)
{
	cos.z1 *= e;
	cos.z2 *= e;
	cos.z3 *= e;
	cos.z4 *= e;
}

void Shape::scaleZCube(int e)
{
	cos.z1 *= e;
	cos.z2 *= e;
	cos.z3 *= e;
	cos.z4 *= e;
	cos.z5 *= e;
	cos.z6 *= e;
	cos.z7 *= e;
	cos.z8 *= e;
}

void Shape::scaleLine(int s)
{
	cos.x1 /= s; cos.y1 /= s;
	cos.x2 /= s; cos.y2 /= s;
}

void Shape::scaleSqr(int s)
{
	cos.x1 /= s; cos.y1 /= s;
	cos.x2 /= s; cos.y2 /= s;
	cos.x3 /= s; cos.y3 /= s;
	cos.x4 /= s; cos.y4 /= s;
}

void Shape::scaleCube(int s)
{
	cos.x1 /= s; cos.y1 /= s; cos.z1 /= s;
	cos.x2 /= s; cos.y2 /= s; cos.z2 /= s;
	cos.x3 /= s; cos.y3 /= s; cos.z3 /= s;
	cos.x4 /= s; cos.y4 /= s; cos.z4 /= s;
	cos.x5 /= s; cos.y5 /= s; cos.z5 /= s;
	cos.x6 /= s; cos.y6 /= s; cos.z6 /= s;
	cos.x7 /= s; cos.y7 /= s; cos.z7 /= s;
	cos.x8 /= s; cos.y8 /= s; cos.z8 /= s;

}

