#pragma once

#define UNDEFINED		-11111

struct Point {
	float x;
	float y;
};

class myMath {
private:

public:
	myMath() {}
	~myMath() {}

	//length
	float getLength(Point a, Point b);
	void findLongestLinePoints(Point p[2], Point a, Point b, Point c);
	void findLongestLinePoints(Point p[2], Point a, Point b, Point c, Point d);
	
	//mid point
	Point getMidPoint(Point a, Point b);

	//slope
	float getRise(Point a, Point b);
	float getRun(Point a, Point b);
	float getSlope(float rise, float run);
	float getSlope(Point a, Point b);
	float getPenpendicularSlope(float slope);

	//compare
	float getBiggerNum(float a, float b);
	float getSmallerNum(float a, float b);

	//intercept
	float getYIntercept(float slope, Point a);
	float getXIntercept(float slope, Point a);

	//crossPoint
	Point getCrossPoint(Point a, Point b, float slopeA, float slopeB);

	//area
	float calculateTriangleArea(Point a, Point b, Point c);
};
