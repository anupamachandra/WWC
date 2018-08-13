void f(double val, int val2)

{
     int x2 = val;         // if val==7.9, x2 becomes 7
     char c2 = val2;       // if val2==1025, c2 becomes 1
     int x3 {val};         // error: possible truncation
     char c3 {val2};       // error: possible narrowing
     char c4 {24};         // OK: 24 can be represented exactly as a char
     char c5 {264};        // error (assuming 8-bit chars): 264 cannot be represented as a char
     int x4 {2.0};         // error: no double to int value conversion
}

int main()
{
	f(7.9, 1025);
}