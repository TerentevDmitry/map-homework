#pragma once
#include "./Catch2/src/catch2/catch_test_macros.hpp"
#include "./Catch2/src/catch2/catch_session.hpp"
#include "shape.h"
#include "Catch2/extras/catch_amalgamated.hpp"
#include <iostream>
#include <cmath>

//2 static const int line = 0;
//2 static const int sqr = 1;
//2 static const int cube = 2;
//3 static const int circle = 3;
//3 static const int cylinder = 4;
// 
//1 Shape() = default;
//2 Shape(int type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
//3 Shape(int type, int _x1, int _y1, double R, double H);

Shape shLine(0, 1,1,0, 3,3,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0);
Shape shSqr(1, 1,1,0, 3,1,0, 3,3,0, 1,3,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0);
Shape shCube(2, 1,1,1, 3,1,1, 3,1,3, 1,1,3, 1,3,3, 1,3,1, 3,3,1, 3,3,3);
Shape shCircle(3, 0, 0, 1, 0);
Shape shCylinder(4, 0, 0, 1, 10);

TEST_CASE("class Shape - test Line", "[testLine]")
{
	SECTION("shLine.getType()")
	{
		CHECK(shLine.getType() == 0);
	}

	SECTION("coordinates Line")
	{
		CHECK(shLine.x1 == 1);
		CHECK(shLine.y1 == 1);
		CHECK(shLine.x2 == 3);
		CHECK(shLine.y2 == 3);
	}

	SECTION("Square Line")
	{
		CHECK(shLine.square == 0.0);
	}

	SECTION("Volume shLine")
	{
		CHECK(shLine.volume == 0.0);
	}
}

TEST_CASE("class Shape - test Sqr", "[testSqr]")
{
	SECTION("shSqr.getType()")
	{
		CHECK(shSqr.getType() == 1);
	}

	SECTION("coordinates Sqr")
	{
		CHECK(shSqr.x1 == 1);
		CHECK(shSqr.y1 == 1);
		CHECK(shSqr.x2 == 3);
		CHECK(shSqr.y2 == 1);
		CHECK(shSqr.x3 == 3);
		CHECK(shSqr.y3 == 3);
		CHECK(shSqr.x4 == 1);
		CHECK(shSqr.y4 == 3);
	}

	SECTION("Square shSqr")
	{
		CHECK(shSqr.square == 4.0);
	}

	SECTION("Volume shSqr")
	{
		CHECK(shSqr.volume == 0.0);
	}
}

TEST_CASE("class Shape - test Cube", "[testCube]")
{
	SECTION("shCube.getType()")
	{
		CHECK(shCube.getType() == 2);
	}

	SECTION("coordinates Cube")
	{
		CHECK(shCube.x1 == 1);
		CHECK(shCube.y1 == 1);
		CHECK(shCube.z1 == 1);
		CHECK(shCube.x2 == 3);
		CHECK(shCube.y2 == 1);
		CHECK(shCube.z2 == 1);
		CHECK(shCube.x3 == 3);
		CHECK(shCube.y3 == 1);
		CHECK(shCube.z3 == 3);
		CHECK(shCube.x4 == 1);
		CHECK(shCube.y4 == 1);
		CHECK(shCube.z4 == 3);
		CHECK(shCube.x5 == 1);
		CHECK(shCube.y5 == 3);
		CHECK(shCube.z5 == 3);
		CHECK(shCube.x6 == 1);
		CHECK(shCube.y6 == 3);
		CHECK(shCube.z6 == 1);
		CHECK(shCube.x7 == 3);
		CHECK(shCube.y7 == 3);
		CHECK(shCube.z7 == 1);
		CHECK(shCube.x8 == 3);
		CHECK(shCube.y8 == 3);
		CHECK(shCube.z8 == 3);
	}

	SECTION("Square Cube")
	{
		CHECK(shCube.square == 24.);
	}

	SECTION("Volume Cube")
	{
		CHECK(shCube.volume == 8.);
	}
}

TEST_CASE("class Shape - test Circle", "[testCircle]")
{
	SECTION("shCircle.getType()")
	{
		CHECK(shCircle.getType() == 3);
	}

	SECTION("coordinates Circle")
	{
		CHECK(shCircle.x1 == 0);
		CHECK(shCircle.y1 == 0);
		CHECK(shCircle.radius == 1.);
	}

	SECTION("Square Circle")
	{
		CHECK(shCircle.square == 3.14159265358979312);
	}

	SECTION("Volume Circle")
	{
		CHECK(shCircle.volume == 0.);
	}
}

TEST_CASE("class Shape - test Cylinder", "[testCylinder]")
{
	SECTION("shCylinder.getType()")
	{
		CHECK(shCylinder.getType() == 4);
	}

	SECTION("coordinates Cylinder")
	{
		CHECK(shCylinder.x1 == 0);
		CHECK(shCylinder.y1 == 0);
		CHECK(shCylinder.radius == 1.);
		CHECK(shCylinder.height == 10.);
	}

	SECTION("Square Cylinder")
	{
		CHECK(shCylinder.square == 69.11503837897544145);
	}

	SECTION("Volume Cylinder")
	{
		CHECK(shCylinder.volume == 31.41592653589793116);
	}
}



int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}