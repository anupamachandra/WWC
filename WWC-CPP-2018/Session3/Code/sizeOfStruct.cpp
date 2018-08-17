#include <iostream>

struct Readout {
     char hour;      //[0:23]
     int value;
     char seq;       
};

int main()
{
 std::cout << sizeof(Readout) << '\n';
}