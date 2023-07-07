//============================================================================
// Name        : LinearAlgebra.h
// Author      : Erik Goras
// Version     : 1.0
// Copyright   : Erik Goras
// e-mail      : goras.erik@gmail.com
// phone       : +46 70 176 36 50
// Created on: 7 juli 2023
//============================================================================

#ifndef LINEARALGEBRA_H_
#define LINEARALGEBRA_H_

#include<iostream>
#include <math.h>
using namespace std;

class Point{
public:
	Point();											//constructors
	Point(double x_init,double y_init, double z_init);
	void setX(double x_init);
	void setY(double y_init);
	void setZ(double z_init);
	void setPoint(double x_init,double y_init, double z_init);
	double getX();
	double getY();
	double getZ();
	friend ostream& operator<<(ostream&, Point&);		//operator overloading
private:
	double x;
	double y;
	double z;
};

class Vector{
public:
 	Vector();										//constructors
	Vector(double x_init,double y_init, double z_init);
	Vector(Point p1,Point p2);
	void setX(double x_init);
	void setY(double y_init);
  	void setZ(double z_init);
  	void setLength(double initLength);
	void setVector(double x_init,double y_init, double z_init);
	void setVector(Point p1,Point p2);
	double getX();
  	double getY();
  	double getZ();
  	double vectorLength();							//length of vector
  	Vector e_Vector();								//unit vector e with size 1
  	Vector operator+(Vector rhs);					//operator overloading
	Vector operator+(double length);
  	Vector operator-(Vector rhs);
  	Vector operator-(double length);
  	Vector operator*(double rhs);
	Vector cross(Vector rhs);						//cross product of two vectors
  	double scalar(Vector rhs);						//scalar product of two vectors
	double angle(Vector rhs);						//angle between two vectors
  	friend ostream& operator<<(ostream&, Vector&);
private:
  	double x;
  	double y;
  	double z;
};

/****** Math Functions ****************************/
double RadToDeg(double radianAngle);
double DegToRad(double degAngle);
double max(double *array, int nums);
double min(double *array, int nums);
/**************************************************/

#endif /* LINEARALGEBRA_H_ */
