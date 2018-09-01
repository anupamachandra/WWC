// Constructors and Destructors

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Tracer {
     string mess;
     Tracer(const string& s) :mess{s} { cout << mess; }
     ~Tracer() {cout << "~" << mess; }
};

void f(const vector<int>& v)
{
    Tracer tr {"in f()\n"};

    for (auto x : v) {
        Tracer tr {string{"v loop "}+to_string(x)+'\n'};
     }
}

int main()
{
	vector<int> v {2,3,5};
	f (v);//f ({2,3,5});
}

// Ref: https://stackoverflow.com/questions/2357452/stdinitializer-list-as-function-argument