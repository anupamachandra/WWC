#include <iostream>
using namespace std;

void update(int* q)
{
	cout << "q points to a[" << *q <<"]" <<endl;
	q++;
	cout << "q points to a[" << *q <<"]" <<endl;
}

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int* p = a;

	cout << "p points to a[" << *p <<"]" <<endl;

	update(p);

	cout << "p points to a[" << *p <<"]" <<endl;

	return 0;

}