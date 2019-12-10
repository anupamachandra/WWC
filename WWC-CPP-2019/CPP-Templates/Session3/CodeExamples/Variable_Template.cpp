#include <iostream>
#include <iomanip>
#include<type_traits>
template<typename T>
T pi = T( 3.1415926535897932384626433L );
template int pi<int>;

template <typename T>
T circular_area(T val) {
    return pi<T> * val * val;
}


constexpr auto get_value() {
    int i= 10;
    return i*5+ 100 +1000;
}

template<typename T>
constexpr T value = T(get_value());

// recursively define variable template, typically done with
// they can be used for complicated examples! 

template<int Value>
constexpr auto fib = fib<Value-1> + fib<Value-2>;
// explicitly specialized
template<>
auto fib<0> = 0;

template<>
auto fib<1> = 1;

// type_triat
template<typename T, typename U>
constexpr bool is_same = false;
// parially specialized
template<typename T>
constexpr bool is_same<T,T> = true;

template<bool Val, typename T, typename U>
U conditional_var;
template<typename T, typename U>
T conditional_var<true, T, U>;

int main2() {
    pi<char> = 'a';          // initializing pi for 'char' type

    //cout << pi; // cant just say print out pi, pi is a template
    std::cout << std::setprecision(20);
    std::cout << pi<int> << std::endl; //instantiate int representation of pi
    std::cout << pi<float> << std::endl; //instantiate float representation of pi
    std::cout << pi<double> << std::endl; // instantiate double - higher precision
    std::cout << pi<long double> << std::endl; // instantiate long double 
    std::cout << pi<char> << std::endl;
    //std::cout << fib<10> << std::endl;
    std::cout << is_same<int, int> << std::endl;
    std::cout << std::conditional_t<std::is_floating_point<float>::value, std::true_type, std::false_type>{} << std::endl;
    std::cout << conditional_var<std::is_floating_point<float>::value, std::true_type, std::false_type> << std::endl;
    return 0;
}