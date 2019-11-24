#include "Vector.h"
#include "Vector_Bool.h"
#include <list>
#include <set>

template class _Vector<int>;  // explicit instantiation, all members
template void _Vector<double>::push_back(double elem); // only push_back()
int main() {
    _Vector<float>* vecFloatPtr; // nothing is instantiated here
    _Vector<float> vecFloat;  // implicit instantiation of Vector<float>
    vecFloatPtr = &vecFloat;
    vecFloat.push_back(true); // instantiation of Vector<float>::push_back()
    bool emptyCont = vecFloatPtr->is_empty(); // of Vector<float>::is_empty()

    _Vector<int> vec; // default constructor
    std::cout << vec.is_empty() << std::endl; // instantiate is_empty
    vec.push_back(10); //instantiate push_back
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    _Vector<int> vec2(vec); // copy constructor
    _Vector<int> vec3(4, 100); // Initialize Constructor
    _Vector<int> vec4; // default constructor
    vec4 = vec2; // copy assignment
    vec2 = vec2; // copy assignment
    _Vector<int> vec5(std::move(vec2)); // move constructor 
    _Vector<int> vec6; //default constructor
    vec6 = std::move(vec5); // move assignment 

    _Vector<int>::_Iter it = vec.begin();  // range iterator begin pointer
    _Vector<int>::_Iter end = vec.end(); // range iterator end pointer
    for (it; it != end; ++it) { // != operator
        std::cout << (*it) << std::endl; // dereference operator
    }

    for (auto i : vec)
        std::cout << i << std::endl;

    while (!vec.is_empty()) {
        std::cout << vec.back() << std::endl; // instantiate back()
        vec.pop_back(); // instantiate pop_back()
    }

    // BOOL Vector
    std::cout << "Size of Bool: " << sizeof(bool) << std::endl;

    _Vector<bool> vecBool3(66, true); // initalize constructor
    std::cout << "Number of elements in vector: " << vecBool3.size() << std::endl;
    //std::cout << "Size in bytes: " << vecBool3.capacity() << std::endl;

    _Vector<bool> vecBool4; //default constructor
    vecBool4 = vecBool3; // copy assignment

    _Vector<bool>::_Iter itBool = vecBool4.begin();
   _Vector<bool>::_Iter endBool = vecBool4.end();

    for (itBool; itBool != endBool; ++itBool) {
        std::cout << (*itBool) << std::endl;
    }
}

