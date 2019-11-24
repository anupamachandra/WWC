#include <iostream>
#include <set>


template<typename Value, typename Alloc = std::allocator<Value>>
using GreaterSet = std::set<Value, std::greater<Value>, Alloc>;
int main() {
    GreaterSet<int> x{ 4, 2, 1, 3 };
    // Iterate 
    for (GreaterSet<int>::iterator it = x.begin(); it != x.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::set<int> s{ 4,2,1,3 };
    for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
        std::cout << ' ' << *it;


    return 0;
}