#include <iostream>
using namespace std;

template <typename T>
T GetMax (T a, T b) {
 return (a>b?a:b);
}

template <typename T, typename U>
int LargerSize(T a, U b)
{
    return sizeof(T) > sizeof(U) ? sizeof(T) : sizeof(U);
}

template <>
char GetMax(char a, char b)
{
	cout << "Invalid Operation \n";
}
int main()
{
    int a = GetMax<int>(2,3);
    float b = GetMax(2.1f,2.2f);
    //char c = GetMax ('a', 'b');

    int  y = LargerSize(a, b);
    cout << y;
}