#include<iostream>
using namespace std;

/*
4545
 4444

 minimum possible number of given value.
*/
int main()
{
	 char A[100000];
	cin>>A;
	int i=0;
	if(A[i]==9)
		i++;
	for(;A[i]!='\0';i++)
	{
		int digit=A[i]-'0';
		if(digit>=5)
		{
			digit=9-digit;
		}
		A[i]=digit+'0';
	}
	cout<<A<<endl;
	return 0;
}	
