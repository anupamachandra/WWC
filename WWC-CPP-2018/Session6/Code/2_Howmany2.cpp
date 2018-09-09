//HowMany2.cpp : The copy-constructor

#include <iostream>
#include <string>
using namespace std;

class HowMany2 {
string name; // Object identifier
static int objectCount;
public:
HowMany2(const string& id = "") : name(id) {
++objectCount;
print("HowMany2()");
}
~HowMany2() {
--objectCount;
print("~HowMany2()");
}
// The copy-constructor:
HowMany2(const HowMany2& h) : name(h.name) {
name += " copy";
++objectCount;
print("HowMany2(const HowMany2&)");
}
void print(const string& msg = "") const {
if(msg.size() != 0)
cout << msg << endl;
cout << '\t' << name << ": "
<< "objectCount = "
<< objectCount << endl;
}
};

int HowMany2::objectCount = 0;

// Pass and return BY VALUE:
HowMany2 f(HowMany2 x) {
x.print("x argument inside f()");
cout << "Returning from f()" << endl;
return x;
}

int main() {
HowMany2 h("h");
cout << "Entering f()" << endl;
HowMany2 h2 = f(h);
h2.print("h2 after call to f()");
} ///:~