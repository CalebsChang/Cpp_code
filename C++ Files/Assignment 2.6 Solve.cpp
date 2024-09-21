#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b;
	cout << "Please enter two intergers: " << endl;
	cin >> a >> b;
	for (int i = a; i <= b; i++) //This will get all # between a & b
	{
		cout << (i * i) * i << endl;
	}

	int Celci, Fahr, FCelci = 0;
	cout << "===========================" << endl;
	cout << endl;
	cout << setw(1) << " " << "Celcius" << setw(7) << " " << "Fahrenheit" << endl;
	cout << endl;
	cout << "===========================" << endl;
	for (int i = 0; i <= 60; i)
	{
		cout << setw(3) << (i += 0) << setw (11) << " " << (((9 / 5.0) * i) + 32) << endl;
		i += 10;
	}
	cout << endl;
	cout << "===========================" << endl;

	return 0;
}