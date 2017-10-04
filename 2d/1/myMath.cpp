#include<cmath>
#include"myMath.h"

float myMath::getLength(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Point myMath::getMidPoint(Point a, Point b)
{
	Point p;
	p.x = (a.x + b.x) / 2;
	p.y = (a.y + b.y) / 2;
	return p'
}

void myMath::findLongestLinePoints(Point p[2], Point a, Point b, Point c)
{//three points
	if (getLength(a, b) > getLength(a, c) && getLength(a, b) > getLength(b, c))
	{
		//a,b
		p[0] = a; 
		p[1] = b;
	}
	else if (getLength(a, c) > getLength(a, b) && getLength(a, c) > getLength(b, c))
	{
		//a,c
		p[0] = a;
		p[1] = c;
	}
	else
	{
		//b,c
		p[0] = b;
		p[1] = c;
	}
}

void myMath::findLongestLinePoints(Point p[2], Point a, Point b, Point c, Point d)
{//four points
	findLongestLinePoints(p, a, b, c);
	if (getLength(p[0], p[1]) < getLength(a, d))
	{
		p[0] = a;
		p[1] = d;
	}
	else if (getLength(p[0], p[1]) < getLength(b, d))
	{
		p[0] = b;
		p[1] = d;
	}
	else if (getLength(p[0], p[1]) < getLength(c, d))
	{
		p[0] = c;
		p[1] = d;
	}
}

float myMath::getRise(Point a, Point b)
{
	return a.y - b.y;
}

float myMath::getRun(Point a, Point b)
{
	return a.x - b.x;
}

float myMath::getSlope(float rise, float run)
{
	if (run == 0) return UNDEFINED;
	float slope = rise / run;
	return slope;
}

float myMath::getSlope(Point a, Point b)
{
	float slope = (getRise(a, b) / getRun(a, b));
	return slope;
}

float myMath::getPenpendicularSlope(float slope)
{
	if (slope == 0) return UNDEFINED;
	return -(1 / slope);
}

float myMath::getBiggerNum(float a, float b)
{
	return (a > b) ? a : b;
}

float myMath::getSmallerNum(float a, float b)
{
	return (a < b) ? a : b;
}

float myMath::getYIntercept(float slope, Point a)
{
	return a.y - (slope * a.x); // <-- b
}

float myMath::getXIntercept(float slope, Point a)
{
	return (getYIntercept(slope, a) * -1) / slope;
}

Point myMath::getCrossPoint(Point a, Point b, float slopeA, float slopeB)
{
	Point p;
	float bYIntercept = getYIntercept(slopeB, b);
	float aYIntercept = getYIntercept(slopeA, a);
	float x = ((bYIntercept - aYIntercept) / (slopeA - slopeB));
	float y = slopeA * x + aYIntercept;

	p.x = x;
	p.y = y;

	return p;
}

float myMath::calculateTriangleArea(Point a, Point b, Point c)
{
	Point m;
	float lenAB = getLength(a, b);
	float lenAC = getLength(a, c);
	float lenBC = getLength(b, c);
	float lenM;
	float slopeAB = getSlope(a, b);
	float slopeAC = getSlope(a, c);
	float slopeBC = getSlope(b, c);
	float perpenSlope;

	if (getBiggerNum(lenAB, lenAC) == getBiggerNum(lenAB, lenBC))
	{//ab
		perpenSlope = getPenpendicularSlope(slopeAB);
		if (UNDEFINED == perpenSlope)
		{
			m.x = c.x;
			m.y = a.y;
		}
		else
			m  = getCrossPoint(a, c, slopeAB, perpenSlope);
		lenM = getLength(m, c);
		return (lenM * lenAB) / 2;
	}
	else if (getBiggerNum(lenAB, lenAC) == getBiggerNum(lenAC, lenBC))
	{//ac
		perpenSlope = getPenpendicularSlope(slopeAC);
		if (UNDEFINED == perpenSlope)
		{
			m.x = b.x;
			m.y = a.y;
		}
		else
 			m = getCrossPoint(a, b, slopeAC, perpenSlope);
		lenM = getLength(m, b);
		return (lenM * lenAC) / 2;
	}
	else
	{//bc
		perpenSlope = getPenpendicularSlope(slopeBC);
		if (UNDEFINED == perpenSlope)
		{
			m.x = a.x;
			m.y = b.y;
		}
		else
			m = getCrossPoint(b, a, slopeBC, perpenSlope);
		lenM = getLength(m, a);
		return (lenM * lenBC) / 2;
	}

	return 0;
}