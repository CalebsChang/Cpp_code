#ifndef PatientRecord_h
#define PatientRecord_h
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class PatientRecord
{
private:
	string lName;
	string fName;
	string pSymp;
	string dateofBirth;
	double pNum;
public:
	//Constuctors
	PatientRecord();
	PatientRecord(string last, string first, string dateofBirth, string PaitentSymp, double PaitentNum);
	//Set and Get Functions
	void setlName(string last);
	string getlName();
	void setfName(string first);
	string getfName();
	void setDOB(string DOB);
	string getDOB();
	void setpSymp(string PaitnetSymp);
	string getpSymp();
	void setpNum(double PaitentNum);
	double getpNum();
	void display();
};
PatientRecord::PatientRecord()
{
	lName = "None";
	fName = "None";
	dateofBirth = "None";
	pSymp = "None";
	pNum = 0;
}
PatientRecord::PatientRecord(string last, string first, string DOB, string PatientSymp, double PatientNum)
{
	lName = last;
	fName = first;
	dateofBirth = DOB;
	pSymp = PatientSymp;
	pNum = PatientNum;
}
void PatientRecord::setlName(string last)
{
	lName = last;
}
string PatientRecord::getlName()
{
	return lName;
}
void PatientRecord::setfName(string first)
{
	fName = first;
}
string PatientRecord::getfName()
{
	return fName;
}
void PatientRecord::setDOB(string DOB)
{
	dateofBirth = DOB;
}
string PatientRecord::getDOB()
{
	return dateofBirth;
}
void PatientRecord::setpSymp(string PatientSymp)
{
	pSymp = PatientSymp;
}
string PatientRecord::getpSymp()
{
	return  pSymp;
}
void PatientRecord::setpNum(double PatientNum)
{
	pNum = PatientNum;
}
double PatientRecord::getpNum()
{
	return pNum;
}
bool operator >(PatientRecord p1, PatientRecord p2)
{
	return p1.getpNum() > p2.getpNum();
}
ostream& operator<<(ostream& out, PatientRecord rec)
{
	rec.display();
	return out;
}
void PatientRecord::display()
{
	cout << "=============================" << endl;
	cout << setw(20) << "Patient's Number:" << setw(10) << pNum << endl;
	cout << setw(20) << "Patient last Name:" << setw(10) << lName << endl;
	cout << setw(20) << "Patient first Name:" << setw(10) << fName << endl;
	cout << setw(20) << "Patient's Date of Birth:" << setw(10) << dateofBirth << endl;
	cout << setw(20) << "Patient's Symptoms:" << setw(10) << pSymp << endl;
	cout << "=============================";
}
#endif
