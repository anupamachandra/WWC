#include <iostream>

template<typename... Arg>
auto adder(Arg...args) {
    std::cout << "Func called";
    return (args + ... + 0);
}

int main5() {
    std::cout << adder(10, 20, 30, 40) << "\n";
    std::cout << adder();
    return 0;
}