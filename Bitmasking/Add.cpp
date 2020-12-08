// C++ Program to add two numbers 
// without using arithmetic operator 
#include <bits/stdc++.h> 
using namespace std; 

int Add(int x, int y) 
{ 
	// Iterate till there is no carry 
	while (y != 0) 
	{ 
		// carry now contains common 
		//set bits of x and y 
		int carry = x & y; 
        // cout<<"Carry->"<<carry;

		// Sum of bits of x and y where at 
		//least one of the bits is not set 
		x = x ^ y; 
		// Carry is shifted by one so that adding 
		// it to x gives the required sum 
		y = carry << 1; 
	} 
	return x; 
} 

int Add_Rec(int x, int y) 
{ 
	if (y == 0) 
		return x; 
	else
		return Add( x ^ y, (x & y) << 1); 
} 

// Driver code 
int main() 
{ 
	cout << Add(10, 5)<<endl; 
    //cout<< Add_Rec(20,25);
	return 0; 
} 


