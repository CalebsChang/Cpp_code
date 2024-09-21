#include<iostream>
#include<string>
#include"PatientRecord.h"
using namespace std;

int main()
{
	PatientRecord recordA;
	PatientRecord recordB("Chang", "Caleb", "Allergies", 10);
	recordA.display();
	recordB.display();
	return 0;
}