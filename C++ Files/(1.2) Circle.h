//Header File of class Circle

#ifndef _Circle
#define _Circle
#include<iostream>
#include<fstream>
using namespace std;

class Circle
{
private:
    double radius;
public:
    Circle();
    Circle(double r);
    void setRadius(double r);
    double getRadius();
    double area();
   
    void display();
    
    Circle operator+ (const Circle & Cir) const;
};
//Definitions of constructors;
Circle::Circle()
{
    radius = 1;
}
Circle::Circle(double r)
{
    radius = r;
}
//Definition of Methods:
void Circle::setRadius(double r)
{
    radius = r;
}
double Circle::getRadius()
{
    return radius;
}
double Circle::area()
{
    return 3.1415926 * radius * radius;
}
void Circle::display()
{
    cout << "This a circle\n";
    cout << "Radius = " << radius << endl;
}
ostream& operator<<(ostream& out, Circle aCircle)
{
    out << "This a circle\n";
    out << "The radius is " << aCircle.getRadius();
    return out;
}
Circle Circle::operator+(const Circle& Cir) const
{
    Circle s;
    s.setRadius(this->radius + Cir.radius);
    return s;
}
#endif

