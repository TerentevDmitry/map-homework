#pragma once
#include<string>

enum class nameOfShapes
{
	line = 0, sqr = 1, cube = 2, circle = 3, cylinder = 4
};
struct coordinatesOfShapes
{
	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;
};




class Shape
{
private:
	static const int line = static_cast<int> (nameOfShapes::line);
	static const int sqr = static_cast<int> (nameOfShapes::sqr);
	static const int cube = static_cast<int> (nameOfShapes::cube);
	static const int circle = static_cast<int> (nameOfShapes::circle);
	static const int cylinder = static_cast<int> (nameOfShapes::cylinder);

	int type = 0;

	double volume = 0.0;
	double square = 0.0;
	double height = 0.0;
	double radius = 0.0;








public:
	
	Shape() = default;
	
	//line
	Shape(int _x1, int _y1, int _x2, int _y2);

	//sqr
	Shape(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);

	//cube
	Shape(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);

	//circle
	Shape(int _x1, int _y1, double R);

	//cylinder
	Shape(int _x1, int _y1, double R, double H);


	
	int getType() const;
	double getVolume() const;
	double getSquare() const;
	double getHeight() const;
	double getRadius() const;
	
	void shiftLine(int m, int n);
	void shiftSqr(int m, int n);
	void shiftCube(int m, int n, int k);
	
	void scaleXLine(int a);
	void scaleXSqr(int a);
	void scaleXCube(int a);
		
	void scaleYLine(int d);
	void scaleYSqr(int d);
	void scaleYCube(int d);
	
	void scaleZLine(int e);
	void scaleZSqr(int e);
	void scaleZCube(int e);

	void scaleLine(int s);
	void scaleSqr(int s);
	void scaleCube(int s);


	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;
	
	
	



	
	
	
	
	
	


	

	
	

};
