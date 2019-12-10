#include <utility>
#include <iostream>
using namespace std;

class X
{

};

void g (X&)
{
	cout << "g() for a variable\n";
}

void g(X const&)
{
	cout << "g() for a constant\n";
}

void g(X&&)
{
	cout << "g() for a movable object\n";
}

// f() forwards argument to g()
template<typename T>
void f(T&& t)
{
	g(forward<T>(t));
}

int main()
{
	X x;
	X const cx;
	f(x);
	f(cx);
	f(X());
}