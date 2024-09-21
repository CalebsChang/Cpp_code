#include<iostream>
using namespace std;
//This is your function that will
//take out blanks spaces
char *removeBlanks(char a[])
{
	char* b = new char[18];
	int i = 0, j = 0, index = 0;
	for (int i = 0; a[i]; i++)
	{
		b[i] = a[i];
	}
	for (int i = 0; a[i]; i++) {
		if (b[i] != ' ') {
			b[index++] = b[i];
		}
	}
	b[index++] = '\0';	
		/*if (a[i] != ' ')
			a[j++] = a[i];
		i++;*/
//	a[j] = '\0';
	return b;
}
int main()
{
	char testArray[18] = {"How is your day?"};
	char* copyArray;
	cout << testArray << endl;
	copyArray = removeBlanks(testArray);
	cout << "==========" << endl;
	cout << copyArray << endl;
	cout << testArray << endl;
	return 0;
}