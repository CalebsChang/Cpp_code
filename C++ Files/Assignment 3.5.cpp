#include<iostream>
#include"PriorityQueue.h"
#include"PatientRecord.h"
using namespace std;

void pRegister()
{
	cout << "Please select one of the following:" << endl;
	cout << "+----------------------------------+" << endl;
	cout << "|  1. Register a Patient           |" << endl;
	cout << "|  2. Display Patients Queue       |" << endl;
	cout << "|  3. Remove a Patient from Queue  |" << endl;
	cout << "|  4. Close the Registration       |" << endl;
	cout << "+----------------------------------+" << endl;
}

void rPatient(PQueue<PatientRecord>& ERQueue)
{
	string fName, lName, pBirth, pSymp;
	int pNum;
	cin.ignore();
	cout << "Enter Patient's first name: " << endl;
	getline(cin, fName);
	cout << "Enter Patient's last name: " << endl;
	getline(cin, lName);
	cout << "Enter Patient's Date of Birth (mm-dd-yyyy): " << endl;
	getline(cin, pBirth);
	cout << "Enter Patient's symptoms: " << endl;
	getline(cin, pSymp);
	cout << "Enter Patient's priority number: " << endl;
	cin >> pNum;
	PatientRecord aRec(fName, lName, pBirth, pSymp, pNum);
	ERQueue.enqueue(aRec);
}
int main()
{
	PQueue<PatientRecord> ERQueue;
	int cMenu, i=0, pRec = 0;
	while (i != 1) {
		pRegister();
		cin >> cMenu;
		if (cMenu == 1) {
			rPatient(ERQueue);
			pRec++;
		}
		else if (cMenu == 2) {
			cout << "Number of Patients in Waiting Room: " << pRec << endl;
			ERQueue.displayQueue();
		}
		else if (cMenu == 3) {
			ERQueue.dequeue();
			if (pRec > 0)
				pRec--;
		}
		else if (cMenu == 4) {
			cout << "Registration is closed! " << endl;
			i = 1;
		}
		else
			cout << "Invalid selection! Try again." << endl;
	}
	return 0;
}