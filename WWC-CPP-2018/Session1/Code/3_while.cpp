#include <iostream>

using namespace std;

  int main()
  {
  	int num_tries = 3;

  	while (num_tries--)
  	{
  		char c;
  		cout << "Enter y or n: ";
  		cin >> c;
  		if (c == 'y' || c == 'n')
  		{
  			cout << "You win!" << endl;
  			return 0;
  		}
  	}

  	cout << "Better Luck Next Time!" << endl;
  	return 0;

  }