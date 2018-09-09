#include <iostream>
#include <string>

using namespace std;

string MakeFood()
{
	return "Noodles";
}

int main()
{
	string s{"Rice"};
	string s2(s); // Calls copy constructor
	string s3(makeFood()); // temp MakeFood, copy, destroy MakeFood()
}