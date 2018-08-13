//2_char.cpp
// Loop to print the integer value of a given character input
#include <iostream>

using namespace std;

void test_char_conversions(char c, signed char sc, unsigned char uc)

{

     char* pc = &uc;                // error: no pointer conversion

     signed char* psc = pc;         // error: no pointer conversion

     unsigned char* puc = pc;       // error: no pointer conversion

     psc = puc;                     // error: no pointer conversion

}

int main()
{
    test_char_conversions();
    
    for(char ch;cin >> ch;)
    {
        cout << "The integer value of " << ch << " is " << int{ch} <<endl;  
    }
}
