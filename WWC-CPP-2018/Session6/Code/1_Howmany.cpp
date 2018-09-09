//1_HowMany.cpp
// A class that counts its objects
#include <iostream>
#include <string>
using namespace std;

class HowMany {
static int objectCount;
string name;
public:
HowMany() { objectCount++; }

static void print(const string& msg = "") 
{
	if(msg.size() != 0) cout << msg << ": ";
	cout << "objectCount = "<< objectCount << endl;
}

~HowMany() {
objectCount--;
print("~HowMany()");
}
};

int HowMany::objectCount = 0;

// Pass and return BY VALUE:
HowMany f(HowMany x) 
{
	x.print("x argument inside f()");
	return x;
}

int main() {
HowMany h;
cout << h.a << "  " << h.b << "\n";
HowMany::print("after construction of h");
HowMany h2 = f(h);
HowMany::print("after call to f()");
} ///:~
