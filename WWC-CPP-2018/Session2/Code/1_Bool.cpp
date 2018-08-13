// 1_Bool.cpp
#include <iostream>
using namespace std;

void f()
{
	// Bool Type Conversions
	bool b1 = 7;       //so b becomes true
	bool b2 {7};       // error: narrowing
	int i1 = true;     // i1 becomes 1
	int i2 {true};     // i2 becomes 1
	bool a{true};
	bool b{true};
	int c = a+b;

	if (c)
	cout << c << " is true"<< endl;

	int d = a-b;

	if(d)
		cout << d << " is true"<< endl;
	else
		cout << d << " is false"<< endl;

 	int e = d-c;

 	if(e)
 		cout << e << " is true"<< endl;
 	else
 		cout << e << " is true"<< endl;

 	int* ptr = new int;
 	if(ptr) // ptr != nullptr
 	{
 		cout << "Yay!! Allocation Succeeded!";
 	}
 }

 int main()
 {

 	f();
 	return 0;
 }
