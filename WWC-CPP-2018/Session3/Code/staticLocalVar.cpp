#include <iostream>
using namespace std;

int f()
{
	static int count = 0;
	return ++count;
}

int main()
{
	cout << "Calling f()..." << f() << endl;
	cout << "Calling f()..." << f() << endl;
	cout << "Calling f()..." << f() << endl;
	cout << "Calling f()..." << f() << endl;
	cout << "Calling f()..." << f() << endl;

	return 0;
}