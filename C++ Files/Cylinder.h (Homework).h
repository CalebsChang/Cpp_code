
#ifndef Cylinder_h
#define Cylinder_h

#include<iostream>
using namespace std;

class Cylinder
{
private:
	double radius;
	double height;
public:
	Cylinder();
	Cylinder(double r, double h);
	void setRad(double r);
	void setHei(double h);
	double getRad();
	double getHei();
	void display();
};
Cylinder::Cylinder()
{
	radius = 0;
	height = 0;
}
Cylinder::Cylinder(double r, double h)
{
	radius = r;
	height = h;
}
//Implementations
void Cylinder::setRad(double r)
{
	radius = r;
}
void Cylinder::setHei(double h)
{
	height = h;
}
double Cylinder::getRad()
{
	return radius;
}
double Cylinder::getHei()
{
	return height;
}
void Cylinder::display()
{
	cout << "This is a Cylinder " << endl;
	cout << "The Radius is: " << radius << endl;
	cout << "The Height is: " << height << endl;
}
#endif