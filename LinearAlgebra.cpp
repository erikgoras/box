//============================================================================
// Name        : LinearAlgebra.cpp
// Author      : Erik Goras
// Version     : 1.0
// Copyright   : Erik Goras
// e-mail      : goras.erik@gmail.com
// phone       : +46 70 176 36 50
// Created on: 7 juli 2023
//============================================================================

#include "LinearAlgebra.h"
using namespace std;

Point::Point()
{
	x=0;
	y=0;
	z=0;
}

Point::Point(double x_init,double y_init, double z_init)
{
	x=x_init;
	y=y_init;
	z=z_init;
}

void Point::setX(double x_init)
{
	x=x_init;
}

void Point::setY(double y_init)
{
	y=y_init;
}

void Point::setZ(double z_init)
{
	z=z_init;
}

void Point::setPoint(double x_init,double y_init, double z_init)
{
	x=x_init;
	y=y_init;
  	z=z_init;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

double Point::getZ()
{
	return z;
}

ostream& operator<<(ostream& os, Point& p)
{
	os << p.getX() << "," << p.getY() << "," << p.getZ();
  	return os;
}


Vector::Vector()
{
	x=0;
	y=0;
	z=0;
}

Vector::Vector(double x_init,double y_init, double z_init)
{
	x=x_init;
	y=y_init;
	z=z_init;
}

Vector::Vector(Point p1,Point p2)
{
	x=p2.getX()-p1.getX();
	y=p2.getY()-p1.getY();
	z=p2.getZ()-p1.getZ();
}

void Vector::setX(double x_init)
{
	x=x_init;
}

void Vector::setY(double y_init)
{
	y=y_init;
}

void Vector::setZ(double z_init)
{
	z=z_init;
}

void Vector::setLength(double initLength)
{
	Vector v2;
	v2.setX(initLength*e_Vector().x);
  	v2.setY(initLength*e_Vector().y);
  	v2.setZ(initLength*e_Vector().z);
  	x=v2.getX();
  	y=v2.getY();
  	z=v2.getZ();
}

void Vector::setVector(double x_init,double y_init, double z_init)
{
	x=x_init;
	y=y_init;
	z=z_init;
}

void Vector::setVector(Point p1,Point p2)
{
	x=p2.getX()-p1.getX();
	y=p2.getY()-p1.getY();
	z=p2.getZ()-p1.getZ();
}

double Vector::getX()
{
	return x;
}

double Vector::getY()
{
	return y;
}

double Vector::getZ()
{
	return z;
}

double Vector::vectorLength()
{
	return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

Vector Vector::e_Vector()
{
	Vector e;
 	if(vectorLength()!=0)
	{	e.setX(x/vectorLength());
		e.setY(y/vectorLength());
   	e.setZ(z/vectorLength());
 	}
	return e;
}

Vector Vector::operator+(Vector rhs)
{
	Vector sum;
	sum.setX(x+rhs.getX());
	sum.setY(y+rhs.getY());
	sum.setZ(z+rhs.getZ());
	return sum;
}

Vector Vector::operator+(double length)			//return vector with added length
{
	return (e_Vector()*length)+(*this);
}

Vector Vector::operator-(Vector rhs)			//return subtracted vector
{
	Vector subtr;
	subtr.setX(x-rhs.getX());
	subtr.setY(y-rhs.getY());
	subtr.setZ(z-rhs.getZ());
	return subtr;
}

Vector Vector::operator-(double length)			//return vector with subtracted length
{
	return (*this)-(e_Vector()*length);
}

Vector Vector::operator*(double rhs)			//return vector multiplied with a number
{
	Vector multiplied;
	multiplied.setX(x*rhs);
	multiplied.setY(y*rhs);
	multiplied.setZ(z*rhs);
	return multiplied;
}

Vector Vector::cross(Vector rhs)				//return cross product of vectors
{
	Vector crossproduct;
	crossproduct.setX((y*rhs.getZ())-(rhs.getY()*z));
	crossproduct.setY(-((x*rhs.getZ())-(rhs.getX()*z)));
	crossproduct.setZ((x*rhs.getY())-(rhs.getX()*y));
	return crossproduct;
}

double Vector::scalar(Vector rhs)				//return scalar product of vectors
{
	double scalarproduct;
	scalarproduct=(rhs.getX()*x)+(rhs.getY()*y)+(rhs.getZ()*z);
	return scalarproduct;
}

double Vector::angle(Vector rhs)				//return angle between two vectors
{
	double theta=0;

	if(vectorLength()*rhs.vectorLength())
	theta=RadToDeg(acos((scalar(rhs))/(vectorLength()*rhs.vectorLength())));
	else
  	theta=0;

  	return theta;
}

ostream& operator<<(ostream& os, Vector& v)
{
	os << v.getX() << "," << v.getY() << "," << v.getZ();
	return os;
}

double RadToDeg(double radianAngle)
{
	return radianAngle*180/M_PI;
}

double DegToRad(double degAngle)
{
	return degAngle*M_PI/180;
}

double max(double *array, int nums)
{
	double max=array[0];
	for(int i=0;i<nums;i++)
  	{if(max<array[i])
    	max=array[i];
		}
	return max;
}

double min(double *array, int nums)
{
	double min=array[0];
	for(int i=0;i<nums;i++)
  	{if(min>array[i])
    	min=array[i];
		}
	return min;
}
