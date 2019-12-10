	#include<iostream>
    #include<vector>
    using namespace std;

    // number of elements in a raw array
	template<typename T, unsigned N>
	std::size_t len(T(&)[N])
	{
		return N;
	}

	//number of elements for a type having size_type
	template <typename T>
	typename T::size_type len(T const& t)
	{
		return t.size();
	}

	int main()
	{
		int a[10];
		cout << len(a) << '\n'; // len() for array matches
		cout << len("tmp") << '\n'; // len() for array matches
		cout << len(vector<int>{1,2,4}); // len for classes with size_type

		//int* p;
		//cout << len(p) << '\n';

		//allocator<int> x;
		//cout << len(x);
	}

