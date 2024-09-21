#include<iostream>
using namespace std;

int sumSquares(int a, int b)
{
	int t = 0;
	int s = 0;
	for (int i = a; i <= b; i++)
		t += pow(i,2);
	
	return t;

};
void flipCoin(int c)
{
	int d = 0, e = 0;
	for (int j=1;j<=c;j++)
	if (rand() % 2 == 0)
	{
		cout << "T";
	}
	else
	{
		cout << "H";
	}

}

int main()
{
	int x, y;
	cout << "Please enter two positive integers." << endl;
	cin >> x >> y;
	cout << "Your number all together with the power is: " << sumSquares(x, y) << endl;
	cout << "=========================================" << endl;
	int c;
	cout << "Please enter an integer: ";
	cin >> c;
	flipCoin(c);

	return 0;
}