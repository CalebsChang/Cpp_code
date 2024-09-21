#include<iostream>
#include<string>
#include"Cylinder.h"
#include"PatientRecord.h"
using namespace std;

int main()
{
	Cylinder cylinderA, cylinderB(2,5);
	cylinderA.setRad(6);
	cylinderA.setHei(8);
	cylinderA.display();
	cout << "==================" << endl;
	cylinderB.display();
	cout << "==================" << endl;
	PatientRecord recordA;
	PatientRecord recordB("Chang", "Caleb", "Allergies", 1);
	recordA.display();
	recordB.display();
	return 0;
}