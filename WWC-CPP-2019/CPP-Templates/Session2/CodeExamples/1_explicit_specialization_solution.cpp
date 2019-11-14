// Example 4: Illustrating Moral #2 
// 
#include <iostream>
using namespace std;
template<class T> 
struct FImpl;

template<class T> 
void f( T t ) { FImpl<T>::f( t ); } // users, don't touch this!

template<class T> 
struct FImpl 
{ 
  static void f( T t ) // users, go ahead and specialize this 
  {
      cout << "Base Class \n";
  } 
};

template<>
struct FImpl<int*>
{
    static void f(int* t)
    {
        cout << "Full Specialization \n";
    }
};
template<class T>
struct FImpl<T*>
{
    static void f(T* t)
    {
        cout << "Partial Specialization \n";
    }
};



int main()
{
    int *p;
    f(p);
}