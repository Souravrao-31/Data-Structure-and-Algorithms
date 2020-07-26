
#include<iostream>

#include<algorithm>
#include<cstring>
using namespace std;

//still working on better solution
//Approach file name- max-frequent-char-1
int main() {

	char s[10000];
	cin.getline(s,' ');
	int n=strlen(s);
	if((n>=1)&&(n<=1000))
	{
		int max=0;
		char mch;
        sort(s,s+n);
		for(int i=0;i<n;i++)
		{
			auto lb=lower_bound(s,s+n,s[i]);
			auto ub=upper_bound(s,s+n,s[i]);
			int f=ub-lb;
			if(f>max)
			{
				max=f;
				mch=s[i];
			}
		}
		cout<<mch;
	}
	return 0;
}