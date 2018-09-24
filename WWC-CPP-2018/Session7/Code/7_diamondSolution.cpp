#include <string>
#include <iostream>

using namespace std;
struct Animal {
  virtual ~Animal() { }
  virtual void eat(){cout << "This is an Animal Eating" << '\n';};
};

// Two classes inheriting Animal:
struct Mammal : virtual Animal {
  virtual void breathe(){ cout << "This is a Mammal Breathing" << '\n';};
};

struct WingedAnimal : virtual Animal {
  virtual void flap(){cout << "This is a WingedAnimal Flapping" << '\n';};
};

// A bat is still a winged mammal
struct Bat : Mammal, WingedAnimal {
};

int main()
{
 Bat b1;
 b1.eat();
}