#pragma once
#include "./Catch2/src/catch2/catch_test_macros.hpp"
#include "./Catch2/src/catch2/catch_session.hpp"
#include "shape.h"
#include "transform.h"
#include "Catch2/extras/catch_amalgamated.hpp"
#include <iostream>
#include <cmath>

Shape shLine(static_cast<int> (nameOfShapes::line), 1,1,0, 3,3,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0);
Shape shSqr(static_cast<int> (nameOfShapes::sqr), 1,1,0, 3,1,0, 3,3,0, 1,3,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0);
Shape shCube(static_cast<int> (nameOfShapes::cube), 1,1,1, 3,1,1, 3,1,3, 1,1,3, 1,3,3, 1,3,1, 3,3,1, 3,3,3);
Shape shCircle(static_cast<int> (nameOfShapes::circle), 0, 0, 1, 0);
Shape shCylinder(static_cast<int> (nameOfShapes::cylinder), 0, 0, 1, 10);

TEST_CASE("class Shape - test Line", "[testLineShape]")
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
		CHECK(shLine.getSquare() == 0.0);
	}

	SECTION("Volume Line")
	{
		CHECK(shLine.getVolume() == 0.0);
	}
}

TEST_CASE("class Shape - test Sqr", "[testSqrShape]")
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
		CHECK(shSqr.getSquare() == 4.0);
	}

	SECTION("Volume shSqr")
	{
		CHECK(shSqr.getVolume() == 0.0);
	}
}

TEST_CASE("class Shape - test Cube", "[testCubeShape]")
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
		CHECK(shCube.getSquare() == 24.);
	}

	SECTION("Volume Cube")
	{
		CHECK(shCube.getVolume() == 8.);
	}
}

TEST_CASE("class Shape - test Circle", "[testCircleShape]")
{
	SECTION("shCircle.getType()")
	{
		CHECK(shCircle.getType() == 3);
	}

	SECTION("coordinates Circle")
	{
		CHECK(shCircle.x1 == 0);
		CHECK(shCircle.y1 == 0);
		CHECK(shCircle.getRadius() == 1.);
	}

	SECTION("Square Circle")
	{
		CHECK(shCircle.getSquare() == 3.14159265358979312);
	}

	SECTION("Volume Circle")
	{
		CHECK(shCircle.getVolume() == 0.);
	}
}

TEST_CASE("class Shape - test Cylinder", "[testCylinderShape]")
{
	SECTION("shCylinder.getType()")
	{
		CHECK(shCylinder.getType() == 4);
	}

	SECTION("coordinates Cylinder")
	{
		CHECK(shCylinder.x1 == 0);
		CHECK(shCylinder.y1 == 0);
		CHECK(shCylinder.getRadius() == 1.);
		CHECK(shCylinder.getHeight() == 10.);
	}

	SECTION("Square Cylinder")
	{
		CHECK(shCylinder.getSquare() == 69.11503837897544145);
	}

	SECTION("Volume Cylinder")
	{
		CHECK(shCylinder.getVolume() == 31.41592653589793116);
	}
}

transform trLine(shLine);
transform trSqr(shSqr);
transform trCube(shCube);

//***************************************************************************************

std::once_flag flag1;
void trLineShift(const int shX, const int shY)
{
	trLine.shift(shX, shY, 0);
}
std::once_flag flag2;
void trLineScaleX(const int scX)
{
	trLine.scaleX(scX);
}
std::once_flag flag3;
void trLineScaleY(const int scY)
{
	trLine.scaleY(scY);
}
std::once_flag flag4;
void trLineScaleZ(const int scZ)
{
	trLine.scaleZ(scZ);
}
std::once_flag flag5;
void trLineScale(const int sc)
{
	trLine.scale(sc);
}

TEST_CASE("class Transform - test Line", "[testLineTransform]")
{
	SECTION("class Transform - test Line")
	{
		const int shX = 1;
		const int shY = 2;
		std::call_once(flag1, trLineShift, shX, shY);

		SECTION("coordinates Line after Shift")
		{

			CHECK(trLine.shape.x1 == 1 + shX);
			CHECK(trLine.shape.y1 == 1 + shY);
			CHECK(trLine.shape.x2 == 3 + shX);
			CHECK(trLine.shape.y2 == 3 + shY);
		}

		SECTION("Square Line after Shift")
		{
			CHECK(trLine.shape.getSquare() == 0.0);
		}

		SECTION("Volume Line after Shift")
		{
			CHECK(trLine.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleX")
	{
		const int scX = 3;
		std::call_once(flag2, trLineScaleX, scX);

		SECTION("coordinates Line after ScaleX")
		{
			CHECK(trLine.shape.x1 == 6);
			CHECK(trLine.shape.y1 == 3);
			CHECK(trLine.shape.x2 == 12);
			CHECK(trLine.shape.y2 == 5);
		}

		SECTION("Square Line after ScaleX")
		{
			CHECK(trLine.shape.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleX")
		{
			CHECK(trLine.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleY")
	{
		const int scY = 4;
		std::call_once(flag3, trLineScaleY, scY);

		SECTION("coordinates Line after ScaleY")
		{
			CHECK(trLine.shape.x1 == 6);
			CHECK(trLine.shape.y1 == 12);
			CHECK(trLine.shape.x2 == 12);
			CHECK(trLine.shape.y2 == 20);
		}

		SECTION("Square Line after ScaleY")
		{
			CHECK(trLine.shape.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleY")
		{
			CHECK(trLine.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleZ")
	{
		const int scZ = 5;
		std::call_once(flag4, trLineScaleZ, scZ);

		SECTION("coordinates Line after ScaleZ")
		{
			CHECK(trLine.shape.z1 == 0);
			CHECK(trLine.shape.z2 == 0);
		}

		SECTION("Square Line after ScaleZ")
		{
			CHECK(trLine.shape.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleZ")
		{
			CHECK(trLine.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line Scale")
	{
		const int sc = 2;
		std::call_once(flag5, trLineScale, sc);

		SECTION("coordinates Line after Scale")
		{
			CHECK(trLine.shape.x1 == 3);
			CHECK(trLine.shape.y1 == 6);
			CHECK(trLine.shape.x2 == 6);
			CHECK(trLine.shape.y2 == 10);
		}

		SECTION("Square Line after Scale")
		{
			CHECK(trLine.shape.getSquare() == 0.0);
		}

		SECTION("Volume Line after Scale")
		{
			CHECK(trLine.shape.getVolume() == 0.0);
		}
	}

}


//***************************************************************************************

std::once_flag flag6;
void trSqrShift(const int shX, const int shY)
{
	trSqr.shift(shX, shY, 0);
}
std::once_flag flag7;
void trSqrScaleX(const int scX)
{
	trSqr.scaleX(scX);
}
std::once_flag flag8;
void trSqrScaleY(const int scY)
{
	trSqr.scaleY(scY);
}
std::once_flag flag9;
void trSqrScaleZ(const int scZ)
{
	trSqr.scaleZ(scZ);
}
std::once_flag flag10;
void trSqrScale(const int sc)
{
	trSqr.scale(sc);
}

TEST_CASE("class Transform - test Sqr", "[testSqrTransform]")
{
	SECTION("class Transform - test Sqr")
	{
		const int shX = 1;
		const int shY = 2;
		std::call_once(flag6, trSqrShift, shX, shY);

		SECTION("coordinates Sqr after Shift")
		{
			CHECK(trSqr.shape.x1 == 2);
			CHECK(trSqr.shape.y1 == 3);
			CHECK(trSqr.shape.x2 == 4);
			CHECK(trSqr.shape.y2 == 3);
			CHECK(trSqr.shape.x3 == 4);
			CHECK(trSqr.shape.y3 == 5);
			CHECK(trSqr.shape.x4 == 2);
			CHECK(trSqr.shape.y4 == 5);
		}

		SECTION("Square Sqr after Shift")
		{
			CHECK(trSqr.shape.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after Shift")
		{
			CHECK(trSqr.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleX")
	{
		const int scX = 3;
		std::call_once(flag7, trSqrScaleX, scX);

		SECTION("coordinates Sqr after ScaleX")
		{
			CHECK(trSqr.shape.x1 == 6);
			CHECK(trSqr.shape.y1 == 3);
			CHECK(trSqr.shape.x2 == 12);
			CHECK(trSqr.shape.y2 == 3);
			CHECK(trSqr.shape.x3 == 12);
			CHECK(trSqr.shape.y3 == 5);
			CHECK(trSqr.shape.x4 == 6);
			CHECK(trSqr.shape.y4 == 5);
		}

		SECTION("Square Sqr after ScaleX")
		{
			CHECK(trSqr.shape.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleX")
		{
			CHECK(trSqr.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleY")
	{
		const int scY = 4;
		std::call_once(flag8, trSqrScaleY, scY);

		SECTION("coordinates Sqr after ScaleY")
		{
			CHECK(trSqr.shape.x1 == 6);
			CHECK(trSqr.shape.y1 == 12);
			CHECK(trSqr.shape.x2 == 12);
			CHECK(trSqr.shape.y2 == 12);
			CHECK(trSqr.shape.x3 == 12);
			CHECK(trSqr.shape.y3 == 20);
			CHECK(trSqr.shape.x4 == 6);
			CHECK(trSqr.shape.y4 == 20);
		}

		SECTION("Square Sqr after ScaleY")
		{
			CHECK(trSqr.shape.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleY")
		{
			CHECK(trSqr.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleZ")
	{
		const int scZ = 5;
		std::call_once(flag9, trSqrScaleZ, scZ);

		SECTION("coordinates Sqr after ScaleZ")
		{
			CHECK(trSqr.shape.z1 == 0);
			CHECK(trSqr.shape.z2 == 0);
			CHECK(trSqr.shape.z3 == 0);
			CHECK(trSqr.shape.z4 == 0);
		}

		SECTION("Square Sqr after ScaleZ")
		{
			CHECK(trSqr.shape.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleZ")
		{
			CHECK(trSqr.shape.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr Scale")
	{
		const int sc = 2;
		std::call_once(flag10, trSqrScale, sc);

		SECTION("coordinates Sqr after Scale")
		{
			CHECK(trSqr.shape.x1 == 3);
			CHECK(trSqr.shape.y1 == 6);
			CHECK(trSqr.shape.x2 == 6);
			CHECK(trSqr.shape.y2 == 6);
			CHECK(trSqr.shape.x3 == 6);
			CHECK(trSqr.shape.y3 == 10);
			CHECK(trSqr.shape.x4 == 3);
			CHECK(trSqr.shape.y4 == 10);
		}

		SECTION("Square Sqr after Scale")
		{
			CHECK(trSqr.shape.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after Scale")
		{
			CHECK(trSqr.shape.getVolume() == 0.0);
		}
	}

}


//***************************************************************************************

std::once_flag flag11;
void trCubeShift(const int shX, const int shY, const int shZ)
{
	trCube.shift(shX, shY, shZ);
}
std::once_flag flag12;
void trCubeScaleX(const int scX)
{
	trCube.scaleX(scX);
}
std::once_flag flag13;
void trCubeScaleY(const int scY)
{
	trCube.scaleY(scY);
}
std::once_flag flag14;
void trCubeScaleZ(const int scZ)
{
	trCube.scaleZ(scZ);
}
std::once_flag flag15;
void trCubeScale(const int sc)
{
	trCube.scale(sc);
}

TEST_CASE("class Transform - test Cube", "[testCubeTransform]")
{
	SECTION("class Transform - test Cube")
	{
		const int shX = 1;
		const int shY = 2;
		const int shZ = 3;

		std::call_once(flag11, trCubeShift, shX, shY, shZ);

		SECTION("coordinates Cube after Shift")
		{
			CHECK(trCube.shape.x1 == 2);
			CHECK(trCube.shape.y1 == 3);
			CHECK(trCube.shape.z1 == 4);
			CHECK(trCube.shape.x2 == 4);
			CHECK(trCube.shape.y2 == 3);
			CHECK(trCube.shape.z2 == 4);
			CHECK(trCube.shape.x3 == 4);
			CHECK(trCube.shape.y3 == 3);
			CHECK(trCube.shape.z3 == 6);
			CHECK(trCube.shape.x4 == 2);
			CHECK(trCube.shape.y4 == 3);
			CHECK(trCube.shape.z4 == 6);
			CHECK(trCube.shape.x5 == 2);
			CHECK(trCube.shape.y5 == 5);
			CHECK(trCube.shape.z5 == 6);
			CHECK(trCube.shape.x6 == 2);
			CHECK(trCube.shape.y6 == 5);
			CHECK(trCube.shape.z6 == 4);
			CHECK(trCube.shape.x7 == 4);
			CHECK(trCube.shape.y7 == 5);
			CHECK(trCube.shape.z7 == 4);
			CHECK(trCube.shape.x8 == 4);
			CHECK(trCube.shape.y8 == 5);
			CHECK(trCube.shape.z8 == 6);
		}

		SECTION("Square Cube after Shift")
		{
			CHECK(trCube.shape.getSquare() == 24.0);
		}

		SECTION("Volume Cube after Shift")
		{
			CHECK(trCube.shape.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleX")
	{
		const int scX = 3;
		std::call_once(flag12, trCubeScaleX, scX);

		SECTION("coordinates Cube after ScaleX")
		{
			CHECK(trCube.shape.x1 == 6);
			CHECK(trCube.shape.y1 == 3);
			CHECK(trCube.shape.z1 == 4);
			CHECK(trCube.shape.x2 == 12);
			CHECK(trCube.shape.y2 == 3);
			CHECK(trCube.shape.z2 == 4);
			CHECK(trCube.shape.x3 == 12);
			CHECK(trCube.shape.y3 == 3);
			CHECK(trCube.shape.z3 == 6);
			CHECK(trCube.shape.x4 == 6);
			CHECK(trCube.shape.y4 == 3);
			CHECK(trCube.shape.z4 == 6);
			CHECK(trCube.shape.x5 == 6);
			CHECK(trCube.shape.y5 == 5);
			CHECK(trCube.shape.z5 == 6);
			CHECK(trCube.shape.x6 == 6);
			CHECK(trCube.shape.y6 == 5);
			CHECK(trCube.shape.z6 == 4);
			CHECK(trCube.shape.x7 == 12);
			CHECK(trCube.shape.y7 == 5);
			CHECK(trCube.shape.z7 == 4);
			CHECK(trCube.shape.x8 == 12);
			CHECK(trCube.shape.y8 == 5);
			CHECK(trCube.shape.z8 == 6);
		}

		SECTION("Square Cube after ScaleX")
		{
			CHECK(trCube.shape.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleX")
		{
			CHECK(trCube.shape.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleY")
	{
		const int scY = 4;
		std::call_once(flag13, trCubeScaleY, scY);

		SECTION("coordinates Cube after ScaleY")
		{
			CHECK(trCube.shape.x1 == 6);
			CHECK(trCube.shape.y1 == 12);
			CHECK(trCube.shape.z1 == 4);
			CHECK(trCube.shape.x2 == 12);
			CHECK(trCube.shape.y2 == 12);
			CHECK(trCube.shape.z2 == 4);
			CHECK(trCube.shape.x3 == 12);
			CHECK(trCube.shape.y3 == 12);
			CHECK(trCube.shape.z3 == 6);
			CHECK(trCube.shape.x4 == 6);
			CHECK(trCube.shape.y4 == 12);
			CHECK(trCube.shape.z4 == 6);
			CHECK(trCube.shape.x5 == 6);
			CHECK(trCube.shape.y5 == 20);
			CHECK(trCube.shape.z5 == 6);
			CHECK(trCube.shape.x6 == 6);
			CHECK(trCube.shape.y6 == 20);
			CHECK(trCube.shape.z6 == 4);
			CHECK(trCube.shape.x7 == 12);
			CHECK(trCube.shape.y7 == 20);
			CHECK(trCube.shape.z7 == 4);
			CHECK(trCube.shape.x8 == 12);
			CHECK(trCube.shape.y8 == 20);
			CHECK(trCube.shape.z8 == 6);
		}

		SECTION("Square Cube after ScaleY")
		{
			CHECK(trCube.shape.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleY")
		{
			CHECK(trCube.shape.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleZ")
	{
		const int scZ = 5;
		std::call_once(flag14, trCubeScaleZ, scZ);

		SECTION("coordinates Cube after ScaleZ")
		{
			CHECK(trCube.shape.x1 == 6);
			CHECK(trCube.shape.y1 == 12);
			CHECK(trCube.shape.z1 == 20);
			CHECK(trCube.shape.x2 == 12);
			CHECK(trCube.shape.y2 == 12);
			CHECK(trCube.shape.z2 == 20);
			CHECK(trCube.shape.x3 == 12);
			CHECK(trCube.shape.y3 == 12);
			CHECK(trCube.shape.z3 == 30);
			CHECK(trCube.shape.x4 == 6);
			CHECK(trCube.shape.y4 == 12);
			CHECK(trCube.shape.z4 == 30);
			CHECK(trCube.shape.x5 == 6);
			CHECK(trCube.shape.y5 == 20);
			CHECK(trCube.shape.z5 == 30);
			CHECK(trCube.shape.x6 == 6);
			CHECK(trCube.shape.y6 == 20);
			CHECK(trCube.shape.z6 == 20);
			CHECK(trCube.shape.x7 == 12);
			CHECK(trCube.shape.y7 == 20);
			CHECK(trCube.shape.z7 == 20);
			CHECK(trCube.shape.x8 == 12);
			CHECK(trCube.shape.y8 == 20);
			CHECK(trCube.shape.z8 == 30);
		}

		SECTION("Square Cube after ScaleZ")
		{
			CHECK(trCube.shape.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleZ")
		{
			CHECK(trCube.shape.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube Scale")
	{
		const int sc = 2;
		std::call_once(flag15, trCubeScale, sc);

		SECTION("coordinates Cube after Scale")
		{
			CHECK(trCube.shape.x1 == 3);
			CHECK(trCube.shape.y1 == 6);
			CHECK(trCube.shape.z1 == 10);
			CHECK(trCube.shape.x2 == 6);
			CHECK(trCube.shape.y2 == 6);
			CHECK(trCube.shape.z2 == 10);
			CHECK(trCube.shape.x3 == 6);
			CHECK(trCube.shape.y3 == 6);
			CHECK(trCube.shape.z3 == 15);
			CHECK(trCube.shape.x4 == 3);
			CHECK(trCube.shape.y4 == 6);
			CHECK(trCube.shape.z4 == 15);
			CHECK(trCube.shape.x5 == 3);
			CHECK(trCube.shape.y5 == 10);
			CHECK(trCube.shape.z5 == 15);
			CHECK(trCube.shape.x6 == 3);
			CHECK(trCube.shape.y6 == 10);
			CHECK(trCube.shape.z6 == 10);
			CHECK(trCube.shape.x7 == 6);
			CHECK(trCube.shape.y7 == 10);
			CHECK(trCube.shape.z7 == 10);
			CHECK(trCube.shape.x8 == 6);
			CHECK(trCube.shape.y8 == 10);
			CHECK(trCube.shape.z8 == 15);
		}

		SECTION("Square Cube after Scale")
		{
			CHECK(trCube.shape.getSquare() == 24.0);
		}

		SECTION("Volume Cube after Scale")
		{
			CHECK(trCube.shape.getVolume() == 8.0);
		}
	}

}







int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}