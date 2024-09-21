#include<iostream>
#include"Bag.h"
#include<iomanip>
using namespace std;

int main()
{
	int a;
	int b;
	Bag myBag;
	for (int i = 0; i < 100; i++)
	{
		myBag.add(rand() % 49);
	}
	cout << "===========" << endl;
	myBag.display();
	cout << endl;
	cout << "========" << endl;
	myBag.sortItems();
	/*cout << "please enter a # pos" << endl;
	cin >> b;
	if (myBag.contain(b))
	{
		cout << "yes it in the bag " << endl;
	}
	else
	{
		cout << "No it not in the bag " << endl;
	}*/
	myBag.display();
	cout << endl;
	cout << "======" << endl;
	/*myBag.getMax();
	cout << "======" << endl;
	myBag.getMin();
	cout << "======" << endl;
	cout << "===========" << endl;
	cout << "Choose a # from the bag: " << endl;
	cin >> a;
	myBag.getPos(a);
	cout << "======" << endl;
	cout << "Choose another # from the bag: " << endl;
	cin >> a;
	myBag.getPos(a);
	cout << "======" << endl;
	cout << "please enter a large # you want to remove from bag: " << endl;
	cin >> a;
	cout << "===========" << endl;
	myBag.remove(a);
	cout << "please enter a small # you want to remove from bag: " << endl;
	cin >> a;
	cout << "===========" << endl;
	myBag.remove(a);
	cout << "===========" << endl;
	cout << "The sum of remaining # and it being divided will be: " << myBag.getSum() << endl;*/
	return 0;

}