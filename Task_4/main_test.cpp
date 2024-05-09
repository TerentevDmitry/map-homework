#pragma once
#include "./Catch2/src/catch2/catch_test_macros.hpp"
#include "./Catch2/src/catch2/catch_session.hpp"
#include "shape.h"
#include "Catch2/extras/catch_amalgamated.hpp"
#include <iostream>

//2 static const int line = 0;
//2 static const int sqr = 1;
//2 static const int cube = 2;
//3 static const int circle = 3;
//3 static const int cylinder = 4;
// 
//1 Shape() = default;
//2 Shape(int type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
//3 Shape(int type, int _x1, int _y1, double R, double H);

Shape shLine(0, 1, 1, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape shSqr(1, 1, 1, 0, 3, 1, 0, 3, 3, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape shCube(2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
Shape shCircle(3, 0, 0, 0, 1);
Shape shCylinder(4, 0, 0, 0, 1);


TEST_CASE("class Shape - test type and coordinates", "[testShapeType—oordinates]")
{
	SECTION("obj.getType()")
	{
		CHECK(shLine.getType() == 0); CHECK(shSqr.getType() == 1); 
		CHECK(shCube.getType() == 2);
		CHECK(shCircle.getType() == 3);
		CHECK(shCylinder.getType() == 4);
	}

	SECTION("coordinates shLine")
	{
		CHECK(shLine.x1 == 1);
		CHECK(shLine.y1 == 1);
		CHECK(shLine.x2 == 3);
		CHECK(shLine.y2 == 3);
	}

	SECTION("coordinates shSqr")
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

	//SECTION("coordinates shCube")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("coordinates shCircle")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("coordinates shCylinder")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}
}

TEST_CASE("class Shape - test square", "[testShapeSquare]")
{
	SECTION("Square shLine")
	{
		CHECK(shLine.square == 0.0);
	}

	SECTION("Square shSqr")
	{
		CHECK(shSqr.square == 0.0);
	}

	//SECTION("Square shCube")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("Square shCircle")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("Square shCylinder")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}
}

TEST_CASE("class Shape - test volume", "[testShapeVolume]")
{
	SECTION("Volume shLine")
	{
		CHECK(shLine.volume == 0.0);
	}

	//SECTION("Square shSqr")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("Square shCube")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("Square shCircle")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}

	//SECTION("Square shCylinder")
	//{
	//	CHECK(shLine.x1 == 0);
	//	CHECK(shLine.y1 == 0);
	//	CHECK(shLine.x2 == 1);
	//	CHECK(shLine.y2 == 1);
	//}
}



int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}