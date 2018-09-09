#include <iostream>
using namespace std;
//Smart Pointer
template <class T>
class SmartPointer{
public:
	SmartPointer(T* ptr){
		ref = ptr;
		ref_count = new int;
		*ref_count = 1;
	}
	
	SmartPointer(SmartPointer<T> &sptr)
	{
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}

	SmartPointer<T> & operator=(SmartPointer<T> sptr)
	{
		if (this == &sptr) return *this;

		if(*ref_count > 0)
		{
			remove();
		}

		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
		return *this;
	}

	~SmartPointer()
	{
		remove(); // remove reference to the object
	}

private:
	void remove()
	{
		--(*ref_count);
		if(*ref_count == 0)
		{
			cout << "Deleting Pointer \n";
			delete ref;
			delete ref_count;
			ref = nullptr;
			ref_count = nullptr;
		}
	}

	T* ref;
	int* ref_count;
};

int main()
{
 int *intptr = new int;
 SmartPointer<int> sptr{intptr};
}