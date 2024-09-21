#include<iostream>
#include<string>
#include"LinkedStack.h"

using namespace std;

int main()
{
	//How to get a another node that will have all items without taking any out like room with pop
	LinkedStack<string> room;
	room.push("floor");
	room.push("table");
	room.push("box");
	room.push("book");
	room.push("phone");
	room.push("cup");
	room.push("pencil");
	//Output should only be phone
	room.display();
	room.pop();
	room.pop();
	string tItem = room.peek();
	cout << "====" << endl;
	cout << tItem << endl;
	cout << "====" << endl;
	return 0;
}