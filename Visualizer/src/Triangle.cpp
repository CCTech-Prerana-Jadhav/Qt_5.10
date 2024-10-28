#include "Triangle.h"

Triangle::Triangle(Point normal, Point p1, Point p2, Point p3)
	: p1(p1), p2(p2), p3(p3), normal(normal)
{
}

Triangle::~Triangle()
{

}

Point Triangle::P1()
{
	return p1;
}

Point Triangle::P2()
{
	return p2;
}

Point Triangle::P3()
{
	return p3;
}

Point Triangle::Normal()
{
	return normal;
}

