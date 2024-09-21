#include<iostream>
using namespace std;

int main()
{
	int enterNum;
	int smallNum = INT_MAX;
	int i = 0;
	while (i < 500) {
		cout << "Please enter an integer: ";
		cin >> enterNum;
		if (smallNum > enterNum)
		{
			smallNum = enterNum;
		}
		i++;
	}
	cout << "The smallest number you entered is: " << smallNum << endl;
	cout << "-----------------------------" << endl;

	//Calculate and display average #
	int input;
	int store=0;
	int b = 0;
	while (b < 200)
	{
		cout << "Please enter an integer: ";
		cin >> input;
		store += input;
		b++; 
	}
	cout << "The Average amount of numbers put in is: " << store/200 << endl;
	cout << "----------------------------------------" << endl;

	//BMI Calulations 
	double BMI, Kilo, Meter;
	int Lb, inch;
	int a = 0;
	while (a < 20) 
	{
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
		cout << "---------------------" << endl;
		a++; 
	}

	return 0;
}