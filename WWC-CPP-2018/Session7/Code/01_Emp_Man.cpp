class Employee {
public:
     void print() const;
     string full_name() const 
     { return first_name + ' ' + middle_initial + ' ' + family_name; }
      //...
private:
     string first_name, family_name;
     char middle_initial;
      //...
};

class Manager : public Employee {
public:
     void print() const;
      //...
};

void Manager::print() const
{
     cout << "name is " << full_name() << '\n';
     //...
}

void Manager::print() const
{
     cout << " name is " << family_name << '\n';    // error!      //...
}

void Manager::print() const

{
     Employee::print();      // print Employee information
     cout << level;          // print Manager-specific information
      //...
}
// Error: Recursive calls to Manager::print resulting in program crash
void Manager::print() const
{
     print();    // oops!
      // print Manager-specific information
}