#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;
	cout << "Enter Two Characters: ";
	cin >> a;
	if (a.length() != 2) {
		cout << "It's an invalid input!" << endl;
	}
	else {
		if (a.at(0) == 'M') {
			switch (a.at(1))
			{
			case '1':
				cout << "Mathmatics Freshmen" << endl;
				break;
			case '2':
				cout << "Mathmatics Sophmore" << endl;
				break;
			case '3':
				cout << "Mathmatics Junior" << endl;
				break;
			case '4':
				cout << "Mathmatics Senior" << endl;
				break;
			default:
				cout << "It's an Invalid inputs" << endl;
				break;
			};

		}
		else if (a.at(0) == 'C') {
			switch (a.at(1))
			{
			case '1':
				cout << "Computer Science Freshmen" << endl;
				break;
			case '2':
				cout << "Computer Science Sophmore" << endl;
				break;
			case '3':
				cout << "Computer Science Junior" << endl;
				break;
			case '4':
				cout << "Computer Science Senior" << endl;
				break;
			default:
				cout << "It's an Invalid inputs" << endl;
				break;
			};
		}
		else if (a.at(0) == 'I') {
			switch (a.at(1))
			{
			case '1':
				cout << "Information Technology Freshmen" << endl;
				break;
			case '2':
				cout << "Information Technology Sophmore" << endl;
				break;
			case '3':
				cout << "Information Techonlogy Junior" << endl;
				break;
			case '4':
				cout << "Informaiton Technology Senior" << endl;
				break;
			default:
				cout << "It's an Invalid inputs" << endl;
				break;
			};
		}
	}
	return 0;
}
