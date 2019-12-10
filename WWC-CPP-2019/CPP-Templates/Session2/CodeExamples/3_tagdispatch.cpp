
#include<iostream>
#include<type_traits>
using namespace std;

int f(int)
{
    return 1;
}

double f(double)
{
    return 1.0;
}

struct dog_type
{

};

struct Dog
{
    string name;
};

template <typename T>
bool Equals(T lhs, T rhs, dog_type)
{
    cout<< "Equals Dog \n";
    return true;
}
template <typename T>
bool Equals(T lhs, T rhs, false_type)
{
    return lhs == rhs;
}

template <typename T>
bool Equals(T lhs, T rhs, true_type)
{
    // Implementation for double
    return true;
}
template <typename T>
bool Equals(T lhs, T rhs)
{
    if constexpr(is_same<T,Dog>::value)
    {
        Equals(lhs, rhs, dog_type{});
    }
    else
    {
        return Equals(lhs, rhs, conditional_t<is_floating_point<T>::value, true_type, false_type>{});
    }
}
int main()
{
    /*cout << "Equals(10, 20) = " << Equals(10, 20) << "\n";
    cout << "Equals(10, 10) = " << Equals(10, 10) << "\n";
    cout << "Equals(10.0, 20.0) = " << Equals(10.0, 20.0) << "\n";
    cout << "Equals(10.02 - 10, 0.02) = " << Equals(10.02 - 10, 0.02) << "\n";
    cout << 10.02 -10;*/
    Dog a;
    Dog b;
    //Dog pa = &a;
    //Dog pb = &b;

    Equals(a, b);

    int c = 10;
    int d = 20;
    int* pc = &c;
    int* pd = &d;

    Equals(pc, pd);
}