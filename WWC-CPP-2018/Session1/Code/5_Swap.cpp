#include <iostream>

void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

int main()
{
	char a{'a'};
	char b{'b'};

	std::cout << "Before Swapping: "<< "a = " << a << " " << "b = " << b << "\n";

	swap(a, b);

	std::cout << "After Swapping: "<< "a = " << a << " " << "b = " << b << "\n";
	return 0;
}