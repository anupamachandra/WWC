// Explicit Specialization
#include<iostream>
using namespace std;

template<class T> // (a) a base template 
void f( T )
{
	cout << "Base template a \n";
}

template<class T> // (b) a second base template, overloads (a) 
void f( T* )
{
	cout << "Template overload b \n";
}

template<>        // (c) explicit specialization of (b) 
void f<>(int*)
{
	cout << "Explicit Specialization c \n";
}

int main()
{
	int *p; 
	f( p );           // calls (c)
}
