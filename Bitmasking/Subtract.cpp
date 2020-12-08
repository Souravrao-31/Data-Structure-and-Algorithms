// C program to Subtract two numbers 
// without using arithmetic operators 
#include<bits/stdc++.h> 
using namespace std;
int subtract(int x, int y) 
{ 
	// Iterate till there 
	// is no carry 
	while (y != 0) 
	{ 
		// borrow contains common 
		// set bits of y and unset 
		// bits of x 
		int borrow = (~x) & y; 

		// Subtraction of bits of x 
		// and y where at least one 
		// of the bits is not set 
		x = x ^ y; 

		// Borrow is shifted by one 
		// so that subtracting it from 
		// x gives the required sum 
		y = borrow << 1; 
	} 
	return x; 
} 

int subtract_Rec(int x, int y) 
{ 
    if (y == 0) 
        return x; 
    return subtract(x ^ y, (~x & y) << 1); 
} 

// Driver Code 
int main() 
{ 
	int x = 29, y = 13; 
	cout<<"x - y is "<< subtract(x, y)<<endl;
    cout<<subtract_Rec(11,1); 
	return 0; 
} 
