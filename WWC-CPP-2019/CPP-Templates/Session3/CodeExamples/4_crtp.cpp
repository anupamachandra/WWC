#include <iostream>
using namespace std;

template <typename Child>
struct Base
{
    void interface()
    {
        static_cast<Child*>(this)->implementation();
    }

    void implementation()
    {
        cerr << "Base Implementation";
    }
};

struct Derived : Base<Derived>
{
    void implementation()
    {
        cerr << "Derived implementation\n";
    }
};

struct Derived2 : Base<Derived2>
{
    void implementation()
    {
        cerr << "Derived2 implementation";
    }
};


int main()
{
    Derived d;
    d.interface();  // Prints "Derived implementation"
    cerr << "\n";
    Derived2 d2;
    d2.interface();
}