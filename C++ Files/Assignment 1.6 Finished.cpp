#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
	srand(time(0));
	int a;
	cout << "Please select one of the followings:" << endl;
	cout << "+----------------------------+" << endl;
	cout << "| 1. To do lists             |" << endl;
	cout << "| 2. Calculate BMI           |" << endl;
	cout << "| 3. Practice Multiplication |" << endl;
	cout << "| 4. Do nothing              |" << endl;
	cout << "+----------------------------+" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "+----------------------------+" << endl;
		cout << "| 1. Do CSI-40 Homework      |" << endl;
		cout << "| 2. Do Astronomy Homework   |" << endl;
		cout << "| 3. Do Laundry and dishes   |" << endl;
		cout << "| 4. Study for Exam          |" << endl;
		cout << "+----------------------------+" << endl;
		break;
	case 2:
		double BMI, Kilo, Meter; 
		int Lb, inch;
		cout << "Please Enter your Body weight in pounds:" << endl;
		cin >> Lb;
		cout << "Please Enter your Body height in inches:" << endl;
		cin >> inch; 
		Kilo = Lb * 0.45359237;
		Meter = pow((inch * 0.0254), 2);
		BMI = Kilo / Meter; 
		cout << "Your body index is: " << BMI << endl; 
		if (BMI < 18.5)
		{
			cout << "You are underweight" << endl;
			cout << "Should try and workout more" << endl;
		}
		if (BMI >= 18.5 and BMI <= 25.0)
		{
			cout << "You are normal" << endl;
			cout << "Keep up with the fit" << endl;
		}
		if (BMI > 25.0 and BMI < 30.0)
		{
			cout << "Your are overweight" << endl;
			cout << "Should try working out sometimes" << endl;
		}
		if (BMI > 30.0)
		{
			cout << "You are obease" << endl;
			cout << "Please consider working out as an option" << endl;
		}
		break;
	case 3:
		int x, y, z;
		x = rand() % 20 + 1;
		y = rand() % 20 + 1;
		cout << x << " x " << y << " = ?" << endl;
		cin >> z;
		if (z == x * y)
		{
			cout << "Nice Job!" << endl;
			cout << "Your answer is correct!" << endl;
		}
		else {
			cout << "Sorry, it's incorrect." << endl;
			cout << "The Correct answer is: " << x * y << endl;
		}
		break;
	case 4:
		cout << "You chose to do nothing, program terminated." << endl;
		break;
	default:
		cout << "Invalid inputs! terminating program" << endl;
	}
	return 0;
}