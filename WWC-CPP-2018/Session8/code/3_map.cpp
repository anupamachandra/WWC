// Find character histogram
#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
	std::map <char, int> char_freq;
	string input;

	cin >> input;
	for(auto x : input)
	{
		char_freq[x]++;
	}

	for (auto elem : char_freq)
	{
		cout << elem.first << '\t' << elem.second << '\n';
	}

	return 0 ;
}