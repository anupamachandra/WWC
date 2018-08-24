#include <iostream>
using namespace std;

// C-like library converted to C++

struct Stash {
  int size;      // Size of each space
  int quantity;  // Number of storage spaces
  int next;      // Next empty space
   // Dynamically allocated array of bytes:
  unsigned char* storage;
  // Functions!
  void initialize(int size);
  void cleanup();
  int add(const void* element);
  void* fetch(int index);
  int count();
  void inflate(int increase);
}; ///:~

struct CStash{
  int size;
  int quantity;
  int next;
  unsigned char* storage; // storage pointer
};

struct A {
  int i[100];
};

struct B {
  void f();
};

void B::f() {}

int main() {
  cout << "sizeof struct A = " << sizeof(A)
       << " bytes" << endl;
  cout << "sizeof struct B = " << sizeof(B)
       << " bytes" << endl;
  cout << "sizeof CStash in C = " 
       << sizeof(CStash) << " bytes" << endl;
  cout << "sizeof Stash in C++ = " 
       << sizeof(Stash) << " bytes" << endl;
} ///:~