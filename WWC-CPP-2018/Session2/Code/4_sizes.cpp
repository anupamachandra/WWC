#include <limits> 
#include <iostream>

using namespace std;
int main()

{

     cout << "size of long " << sizeof(1L) << '\n';
     cout << "size of long long " << sizeof(1LL) << '\n';

     cout << "largest float == " << std::numeric_limits<float>::max() << '\n';
     cout << "char is signed == " << std::numeric_limits<char>::is_signed << '\n';

     static_assert(sizeof(long long) >= 4, "Insufficient size for long long");

     int a[10] ={};

     cout << "size of a is " << sizeof(a) << '\n';

}