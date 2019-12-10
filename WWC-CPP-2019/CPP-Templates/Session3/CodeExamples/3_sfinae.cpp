#include<iostream>
using namespace std;

template<typename T, enable_if_t<!is_floating_point<T>::value>* = nullptr>
bool Equals(T lhs, T rhs)
{
    return lhs == rhs;
}
template<typename T, enable_if_t<is_floating_point<T>::value>* = nullptr>
 bool Equals(T lhs, T rhs)
 {
     // handle precision
     return true;
 }

int main()
{
    cout << boolalpha << '\n';
    cout << Equals(10 , 20) << '\n';
    cout << Equals(10.0, 20.0) << '\n';

}