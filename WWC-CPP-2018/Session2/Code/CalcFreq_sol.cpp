// Write a program that prints character frequency in a sting.
#include <iostream>
using namespace std;
void CalcFreq(const char* input)
{
    int hist[26] =  {};
    
    for (; *input != '\0'; input++)
        hist[*input -'a']++;

    int j = 0;  
    for(auto i : hist)
        cout << (char)(j++ + 'a') << i << endl;
}

int main()
{
	char* input = "donotworrybehappy";
	CalcFreq(input);
}
