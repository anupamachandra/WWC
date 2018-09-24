#include <iostream>
#include <string>
#include <list>
using namespace std;
class Employee {
public:
     Employee(const string& name, int dept): family_name{name}, department{dept}{}
     /*virtual*/ void print() const;
      //...
private:
     string first_name, family_name;
     int department;
      //...
};
void Employee::print() const
{
     cout << family_name << '\t' << department << '\n';
      //...
}

class Manager : public Employee {
public:
     Manager(const string& name, int dept, int lvl): Employee{name, dept}, level{level}{}
     void print() const;
      //...
private:
     list<Employee*> group;
     int level;
      //...
};
void Manager::print() const
{
     Employee::print();
     cout << "\tlevel " << level << '\n';
      //...
}

void print_list(const list<Employee*>& s)
{
    for (auto x : s)
        x->print();
}

int main()
{
    Employee e {"Brown",1234};
    Manager m {"Smith",1234,2};
    print_list({&m,&e});
}