#pragma once
#include "./Catch2/src/catch2/catch_test_macros.hpp"
#include "./Catch2/src/catch2/catch_session.hpp"
#include "shape.h"
#include "transform.h"
#include "Catch2/extras/catch_amalgamated.hpp"
#include <iostream>
#include <cmath>

Shape shLine(1, 1, 3, 3);
Shape shSqr(1, 1, 3, 1, 3, 3, 1, 3);
Shape shCube(1, 1, 1, 3, 1, 1, 3, 1, 3, 1, 1, 3, 1, 3, 3, 1, 3, 1, 3, 3, 1, 3, 3, 3);
Shape shCircle(0, 0, 1);
Shape shCylinder(0, 0, 1., 10.);

TEST_CASE("class Shape - test Line", "[testLineShape]")
{
	SECTION("shLine.getType()")
	{
		CHECK(shLine.getType() == 0);
	}

	SECTION("coordinates Line")
	{
		CHECK(shLine.cosForMain().x1 == 1);
		CHECK(shLine.cosForMain().y1 == 1);
		CHECK(shLine.cosForMain().x2 == 3);
		CHECK(shLine.cosForMain().y2 == 3);
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
		CHECK(shSqr.cosForMain().x1 == 1);
		CHECK(shSqr.cosForMain().y1 == 1);
		CHECK(shSqr.cosForMain().x2 == 3);
		CHECK(shSqr.cosForMain().y2 == 1);
		CHECK(shSqr.cosForMain().x3 == 3);
		CHECK(shSqr.cosForMain().y3 == 3);
		CHECK(shSqr.cosForMain().x4 == 1);
		CHECK(shSqr.cosForMain().y4 == 3);
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
		CHECK(shCube.cosForMain().x1 == 1);
		CHECK(shCube.cosForMain().y1 == 1);
		CHECK(shCube.cosForMain().z1 == 1);
		CHECK(shCube.cosForMain().x2 == 3);
		CHECK(shCube.cosForMain().y2 == 1);
		CHECK(shCube.cosForMain().z2 == 1);
		CHECK(shCube.cosForMain().x3 == 3);
		CHECK(shCube.cosForMain().y3 == 1);
		CHECK(shCube.cosForMain().z3 == 3);
		CHECK(shCube.cosForMain().x4 == 1);
		CHECK(shCube.cosForMain().y4 == 1);
		CHECK(shCube.cosForMain().z4 == 3);
		CHECK(shCube.cosForMain().x5 == 1);
		CHECK(shCube.cosForMain().y5 == 3);
		CHECK(shCube.cosForMain().z5 == 3);
		CHECK(shCube.cosForMain().x6 == 1);
		CHECK(shCube.cosForMain().y6 == 3);
		CHECK(shCube.cosForMain().z6 == 1);
		CHECK(shCube.cosForMain().x7 == 3);
		CHECK(shCube.cosForMain().y7 == 3);
		CHECK(shCube.cosForMain().z7 == 1);
		CHECK(shCube.cosForMain().x8 == 3);
		CHECK(shCube.cosForMain().y8 == 3);
		CHECK(shCube.cosForMain().z8 == 3);
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
		CHECK(shCircle.cosForMain().x1 == 0);
		CHECK(shCircle.cosForMain().y1 == 0);
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
		CHECK(shCylinder.cosForMain().x1 == 0);
		CHECK(shCylinder.cosForMain().y1 == 0);
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


//transform trLine(shLine);
//transform trSqr(shSqr);
//transform trCube(shCube);

//***************************************************************************************

std::once_flag flag1;
void trLineShift(const int shX, const int shY)
{
	shLine.shiftLine(shX, shY);
}
std::once_flag flag2;
void trLineScaleX(const int scX)
{
	shLine.scaleXLine(scX);
}
std::once_flag flag3;
void trLineScaleY(const int scY)
{
	shLine.scaleYLine(scY);
}
std::once_flag flag4;
void trLineScaleZ(const int scZ)
{
	shLine.scaleZLine(scZ);
}
std::once_flag flag5;
void trLineScale(const int sc)
{
	shLine.scaleLine(sc);
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

			CHECK(shLine.cosForMain().x1 == 1 + shX);
			CHECK(shLine.cosForMain().y1 == 1 + shY);
			CHECK(shLine.cosForMain().x2 == 3 + shX);
			CHECK(shLine.cosForMain().y2 == 3 + shY);
		}

		SECTION("Square Line after Shift")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after Shift")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleX")
	{
		const int scX = 3;
		std::call_once(flag2, trLineScaleX, scX);

		SECTION("coordinates Line after ScaleX")
		{
			CHECK(shLine.cosForMain().x1 == 6);
			CHECK(shLine.cosForMain().y1 == 3);
			CHECK(shLine.cosForMain().x2 == 12);
			CHECK(shLine.cosForMain().y2 == 5);
		}

		SECTION("Square Line after ScaleX")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleX")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleY")
	{
		const int scY = 4;
		std::call_once(flag3, trLineScaleY, scY);

		SECTION("coordinates Line after ScaleY")
		{
			CHECK(shLine.cosForMain().x1 == 6);
			CHECK(shLine.cosForMain().y1 == 12);
			CHECK(shLine.cosForMain().x2 == 12);
			CHECK(shLine.cosForMain().y2 == 20);
		}

		SECTION("Square Line after ScaleY")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleY")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleZ")
	{
		const int scZ = 5;
		std::call_once(flag4, trLineScaleZ, scZ);

		SECTION("coordinates Line after ScaleZ")
		{
			CHECK(shLine.cosForMain().z1 == 0);
			CHECK(shLine.cosForMain().z2 == 0);
		}

		SECTION("Square Line after ScaleZ")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleZ")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line Scale")
	{
		const int sc = 2;
		std::call_once(flag5, trLineScale, sc);

		SECTION("coordinates Line after Scale")
		{
			CHECK(shLine.cosForMain().x1 == 3);
			CHECK(shLine.cosForMain().y1 == 6);
			CHECK(shLine.cosForMain().x2 == 6);
			CHECK(shLine.cosForMain().y2 == 10);
		}

		SECTION("Square Line after Scale")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after Scale")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

}


//***************************************************************************************

std::once_flag flag6;
void trSqrShift(const int shX, const int shY)
{
	shSqr.shiftSqr(shX, shY);
}
std::once_flag flag7;
void trSqrScaleX(const int scX)
{
	shSqr.scaleXSqr(scX);
}
std::once_flag flag8;
void trSqrScaleY(const int scY)
{
	shSqr.scaleYSqr(scY);
}
std::once_flag flag9;
void trSqrScaleZ(const int scZ)
{
	shSqr.scaleZSqr(scZ);
}
std::once_flag flag10;
void trSqrScale(const int sc)
{
	shSqr.scaleSqr(sc);
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
			CHECK(shSqr.cosForMain().x1 == 2);
			CHECK(shSqr.cosForMain().y1 == 3);
			CHECK(shSqr.cosForMain().x2 == 4);
			CHECK(shSqr.cosForMain().y2 == 3);
			CHECK(shSqr.cosForMain().x3 == 4);
			CHECK(shSqr.cosForMain().y3 == 5);
			CHECK(shSqr.cosForMain().x4 == 2);
			CHECK(shSqr.cosForMain().y4 == 5);
		}

		SECTION("Square Sqr after Shift")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after Shift")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleX")
	{
		const int scX = 3;
		std::call_once(flag7, trSqrScaleX, scX);

		SECTION("coordinates Sqr after ScaleX")
		{
			CHECK(shSqr.cosForMain().x1 == 6);
			CHECK(shSqr.cosForMain().y1 == 3);
			CHECK(shSqr.cosForMain().x2 == 12);
			CHECK(shSqr.cosForMain().y2 == 3);
			CHECK(shSqr.cosForMain().x3 == 12);
			CHECK(shSqr.cosForMain().y3 == 5);
			CHECK(shSqr.cosForMain().x4 == 6);
			CHECK(shSqr.cosForMain().y4 == 5);
		}

		SECTION("Square Sqr after ScaleX")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleX")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleY")
	{
		const int scY = 4;
		std::call_once(flag8, trSqrScaleY, scY);

		SECTION("coordinates Sqr after ScaleY")
		{
			CHECK(shSqr.cosForMain().x1 == 6);
			CHECK(shSqr.cosForMain().y1 == 12);
			CHECK(shSqr.cosForMain().x2 == 12);
			CHECK(shSqr.cosForMain().y2 == 12);
			CHECK(shSqr.cosForMain().x3 == 12);
			CHECK(shSqr.cosForMain().y3 == 20);
			CHECK(shSqr.cosForMain().x4 == 6);
			CHECK(shSqr.cosForMain().y4 == 20);
		}

		SECTION("Square Sqr after ScaleY")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleY")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleZ")
	{
		const int scZ = 5;
		std::call_once(flag9, trSqrScaleZ, scZ);

		SECTION("coordinates Sqr after ScaleZ")
		{
			CHECK(shSqr.cosForMain().z1 == 0);
			CHECK(shSqr.cosForMain().z2 == 0);
			CHECK(shSqr.cosForMain().z3 == 0);
			CHECK(shSqr.cosForMain().z4 == 0);
		}

		SECTION("Square Sqr after ScaleZ")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleZ")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr Scale")
	{
		const int sc = 2;
		std::call_once(flag10, trSqrScale, sc);

		SECTION("coordinates Sqr after Scale")
		{
			CHECK(shSqr.cosForMain().x1 == 3);
			CHECK(shSqr.cosForMain().y1 == 6);
			CHECK(shSqr.cosForMain().x2 == 6);
			CHECK(shSqr.cosForMain().y2 == 6);
			CHECK(shSqr.cosForMain().x3 == 6);
			CHECK(shSqr.cosForMain().y3 == 10);
			CHECK(shSqr.cosForMain().x4 == 3);
			CHECK(shSqr.cosForMain().y4 == 10);
		}

		SECTION("Square Sqr after Scale")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after Scale")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

}


//***************************************************************************************

std::once_flag flag11;
void trCubeShift(const int shX, const int shY, const int shZ)
{
	shCube.shiftCube(shX, shY, shZ);
}
std::once_flag flag12;
void trCubeScaleX(const int scX)
{
	shCube.scaleXCube(scX);
}
std::once_flag flag13;
void trCubeScaleY(const int scY)
{
	shCube.scaleYCube(scY);
}
std::once_flag flag14;
void trCubeScaleZ(const int scZ)
{
	shCube.scaleZCube(scZ);
}
std::once_flag flag15;
void trCubeScale(const int sc)
{
	shCube.scaleCube(sc);
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
			CHECK(shCube.cosForMain().x1 == 2);
			CHECK(shCube.cosForMain().y1 == 3);
			CHECK(shCube.cosForMain().z1 == 4);
			CHECK(shCube.cosForMain().x2 == 4);
			CHECK(shCube.cosForMain().y2 == 3);
			CHECK(shCube.cosForMain().z2 == 4);
			CHECK(shCube.cosForMain().x3 == 4);
			CHECK(shCube.cosForMain().y3 == 3);
			CHECK(shCube.cosForMain().z3 == 6);
			CHECK(shCube.cosForMain().x4 == 2);
			CHECK(shCube.cosForMain().y4 == 3);
			CHECK(shCube.cosForMain().z4 == 6);
			CHECK(shCube.cosForMain().x5 == 2);
			CHECK(shCube.cosForMain().y5 == 5);
			CHECK(shCube.cosForMain().z5 == 6);
			CHECK(shCube.cosForMain().x6 == 2);
			CHECK(shCube.cosForMain().y6 == 5);
			CHECK(shCube.cosForMain().z6 == 4);
			CHECK(shCube.cosForMain().x7 == 4);
			CHECK(shCube.cosForMain().y7 == 5);
			CHECK(shCube.cosForMain().z7 == 4);
			CHECK(shCube.cosForMain().x8 == 4);
			CHECK(shCube.cosForMain().y8 == 5);
			CHECK(shCube.cosForMain().z8 == 6);
		}

		SECTION("Square Cube after Shift")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after Shift")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleX")
	{
		const int scX = 3;
		std::call_once(flag12, trCubeScaleX, scX);

		SECTION("coordinates Cube after ScaleX")
		{
			CHECK(shCube.cosForMain().x1 == 6);
			CHECK(shCube.cosForMain().y1 == 3);
			CHECK(shCube.cosForMain().z1 == 4);
			CHECK(shCube.cosForMain().x2 == 12);
			CHECK(shCube.cosForMain().y2 == 3);
			CHECK(shCube.cosForMain().z2 == 4);
			CHECK(shCube.cosForMain().x3 == 12);
			CHECK(shCube.cosForMain().y3 == 3);
			CHECK(shCube.cosForMain().z3 == 6);
			CHECK(shCube.cosForMain().x4 == 6);
			CHECK(shCube.cosForMain().y4 == 3);
			CHECK(shCube.cosForMain().z4 == 6);
			CHECK(shCube.cosForMain().x5 == 6);
			CHECK(shCube.cosForMain().y5 == 5);
			CHECK(shCube.cosForMain().z5 == 6);
			CHECK(shCube.cosForMain().x6 == 6);
			CHECK(shCube.cosForMain().y6 == 5);
			CHECK(shCube.cosForMain().z6 == 4);
			CHECK(shCube.cosForMain().x7 == 12);
			CHECK(shCube.cosForMain().y7 == 5);
			CHECK(shCube.cosForMain().z7 == 4);
			CHECK(shCube.cosForMain().x8 == 12);
			CHECK(shCube.cosForMain().y8 == 5);
			CHECK(shCube.cosForMain().z8 == 6);
		}

		SECTION("Square Cube after ScaleX")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleX")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleY")
	{
		const int scY = 4;
		std::call_once(flag13, trCubeScaleY, scY);

		SECTION("coordinates Cube after ScaleY")
		{
			CHECK(shCube.cosForMain().x1 == 6);
			CHECK(shCube.cosForMain().y1 == 12);
			CHECK(shCube.cosForMain().z1 == 4);
			CHECK(shCube.cosForMain().x2 == 12);
			CHECK(shCube.cosForMain().y2 == 12);
			CHECK(shCube.cosForMain().z2 == 4);
			CHECK(shCube.cosForMain().x3 == 12);
			CHECK(shCube.cosForMain().y3 == 12);
			CHECK(shCube.cosForMain().z3 == 6);
			CHECK(shCube.cosForMain().x4 == 6);
			CHECK(shCube.cosForMain().y4 == 12);
			CHECK(shCube.cosForMain().z4 == 6);
			CHECK(shCube.cosForMain().x5 == 6);
			CHECK(shCube.cosForMain().y5 == 20);
			CHECK(shCube.cosForMain().z5 == 6);
			CHECK(shCube.cosForMain().x6 == 6);
			CHECK(shCube.cosForMain().y6 == 20);
			CHECK(shCube.cosForMain().z6 == 4);
			CHECK(shCube.cosForMain().x7 == 12);
			CHECK(shCube.cosForMain().y7 == 20);
			CHECK(shCube.cosForMain().z7 == 4);
			CHECK(shCube.cosForMain().x8 == 12);
			CHECK(shCube.cosForMain().y8 == 20);
			CHECK(shCube.cosForMain().z8 == 6);
		}

		SECTION("Square Cube after ScaleY")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleY")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleZ")
	{
		const int scZ = 5;
		std::call_once(flag14, trCubeScaleZ, scZ);

		SECTION("coordinates Cube after ScaleZ")
		{
			CHECK(shCube.cosForMain().x1 == 6);
			CHECK(shCube.cosForMain().y1 == 12);
			CHECK(shCube.cosForMain().z1 == 20);
			CHECK(shCube.cosForMain().x2 == 12);
			CHECK(shCube.cosForMain().y2 == 12);
			CHECK(shCube.cosForMain().z2 == 20);
			CHECK(shCube.cosForMain().x3 == 12);
			CHECK(shCube.cosForMain().y3 == 12);
			CHECK(shCube.cosForMain().z3 == 30);
			CHECK(shCube.cosForMain().x4 == 6);
			CHECK(shCube.cosForMain().y4 == 12);
			CHECK(shCube.cosForMain().z4 == 30);
			CHECK(shCube.cosForMain().x5 == 6);
			CHECK(shCube.cosForMain().y5 == 20);
			CHECK(shCube.cosForMain().z5 == 30);
			CHECK(shCube.cosForMain().x6 == 6);
			CHECK(shCube.cosForMain().y6 == 20);
			CHECK(shCube.cosForMain().z6 == 20);
			CHECK(shCube.cosForMain().x7 == 12);
			CHECK(shCube.cosForMain().y7 == 20);
			CHECK(shCube.cosForMain().z7 == 20);
			CHECK(shCube.cosForMain().x8 == 12);
			CHECK(shCube.cosForMain().y8 == 20);
			CHECK(shCube.cosForMain().z8 == 30);
		}

		SECTION("Square Cube after ScaleZ")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleZ")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube Scale")
	{
		const int sc = 2;
		std::call_once(flag15, trCubeScale, sc);

		SECTION("coordinates Cube after Scale")
		{
			CHECK(shCube.cosForMain().x1 == 3);
			CHECK(shCube.cosForMain().y1 == 6);
			CHECK(shCube.cosForMain().z1 == 10);
			CHECK(shCube.cosForMain().x2 == 6);
			CHECK(shCube.cosForMain().y2 == 6);
			CHECK(shCube.cosForMain().z2 == 10);
			CHECK(shCube.cosForMain().x3 == 6);
			CHECK(shCube.cosForMain().y3 == 6);
			CHECK(shCube.cosForMain().z3 == 15);
			CHECK(shCube.cosForMain().x4 == 3);
			CHECK(shCube.cosForMain().y4 == 6);
			CHECK(shCube.cosForMain().z4 == 15);
			CHECK(shCube.cosForMain().x5 == 3);
			CHECK(shCube.cosForMain().y5 == 10);
			CHECK(shCube.cosForMain().z5 == 15);
			CHECK(shCube.cosForMain().x6 == 3);
			CHECK(shCube.cosForMain().y6 == 10);
			CHECK(shCube.cosForMain().z6 == 10);
			CHECK(shCube.cosForMain().x7 == 6);
			CHECK(shCube.cosForMain().y7 == 10);
			CHECK(shCube.cosForMain().z7 == 10);
			CHECK(shCube.cosForMain().x8 == 6);
			CHECK(shCube.cosForMain().y8 == 10);
			CHECK(shCube.cosForMain().z8 == 15);
		}

		SECTION("Square Cube after Scale")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after Scale")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}