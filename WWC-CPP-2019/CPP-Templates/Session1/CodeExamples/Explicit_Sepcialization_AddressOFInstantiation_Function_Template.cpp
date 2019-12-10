#include <iostream>
#include <string.h>

template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template int min<int>(int, int);
template float min(float, float);
//extern template double min(double, double);

template<typename T>
T wrapper(T(*func)(T, T), T a, T b) {
    return func(a, b);
}

template<>
const char* min(const char* a, const char *b) {
    return strcmp(a, b) < 0 ? a : b;
}

int main() {

    ::min(10, 20);
    //::min(myclass{10}, myclass{20});
    ::min<int>(10, 20);
    ::min(10.0, 20.0);
    ::min<float>(10.0, 20.0);
    ::min<char>('x', 20.0);
    wrapper<unsigned int>(min, 10, 20);
    const char* b = { "AAA" };
    const char* a = { "ABBB" };
    std::cout << ::min(b, a) << std::endl;

    return 0;
}
