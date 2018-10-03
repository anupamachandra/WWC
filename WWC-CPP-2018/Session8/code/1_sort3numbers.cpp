#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int GetInteger()
{
	int input = 0;
	cin >> input;
	return input;
}

int main() {
int val1 = GetInteger();
int val2 = GetInteger();
int val3 = GetInteger();

cout  << val1 << '\n' << val2 << '\n' << val3 << '\n';
if (val2 <= val1 && val2 <= val3) // val2 is smallest
swap (val1, val2);
else if (val3 <= val1 && val3 <= val2) // val3 is smallest
swap (val1, val3);

if (val3 <= val2) // val3 is smaller
swap (val2, val3);

cout << val1 << ' ' << val2 << ' ' << val3 << endl;
}