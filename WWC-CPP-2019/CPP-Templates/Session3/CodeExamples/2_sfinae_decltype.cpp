	#include<iostream>
    #include<vector>
    using namespace std;
    
	template <typename T>
	auto len (T const& t) ->decltype((void) t.size(), typename T::size_type())
	{
		return t.size();
	}

	int main()
	{
		cout << len(vector<int>{1,2,4}); // len for classes with size_type

		//allocator<int> x; // ERROR no matching len() 
		//cout << len(x);
	}

