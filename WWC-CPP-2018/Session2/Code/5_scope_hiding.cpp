// Scope.cpp
#include <iostream>
using namespace std;

namespace my_namespace
{
	int my_name;

}

int x;
void f()
{
	cout << "1: " << x << endl;
    int x;          // local x hides global x
    cout << "2: " << x << endl;
    x = 1;          // assign to local x
    cout << "3: " << x << endl;
    {

          int x;     // hides first local x
          cout << "4: " << x << endl;

          x = 2;     // assign to second local x
          cout << "5: " << x << endl;

    }
	cout << "6: " << x << endl;
     x = 3;          // assign to first local x
    cout << "7: " << x << endl;
}

int main()
{
	f();
	cout << my_namespace::my_name << endl;
	return 0;
}