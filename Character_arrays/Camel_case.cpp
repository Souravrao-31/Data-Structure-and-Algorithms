#include<iostream>
#include<string>
using namespace std;
int main() 
{
	string S;
	getline(cin,S);
	int len=S.length();
	int i=0;
	for(int i=0;i<len;i++)
	{
	    if(i==0 && S[i]>='A' && S[i]<='Z')
	    {
	        cout<<S[i];
	    }
	    else if(S[i]>='a'&& S[i]<='z')
	    {
	        cout<<S[i];
	    }
	    else if(S[i]>='A' && S[i]<='Z')
	    {
	        cout<<endl;
	        cout<<S[i];
	    }
	}
	return 0;
}
