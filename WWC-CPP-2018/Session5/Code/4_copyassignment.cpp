#include <iostream>
#include <string>
#include <algorithm>
 
struct A
{
    int n;
    std::string s1;
    // user-defined copy assignment, copy-and-swap form
    A& operator=(A other)
    {
        std::cout << "copy assignment of A\n";
        std::swap(n, other.n);
        std::swap(s1, other.s1);
        return *this;
    }
};
 
int main()
{
    A a1, a2;
    a1.s1 = "foo";
    a2.s1 = "bar";
    std::cout << "a1.s1 = " << a1.s1 << " a2.s1 = " << a2.s1 << '\n';
    std::cout << "a1 = a2 calls ";
    a1 = a2; // user-defined copy assignment
    std::cout << "a1.s1 = " << a1.s1 << " a2.s1 = " << a2.s1 << '\n';
}