#include<iostream>
using namespace std;
int ans=0;
void subs(char *inp,char *out,int i,int j)
{
	if(inp[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<" ";
		return;
	}
    subs(inp,out,i+1,j);
	out[j]=inp[i];
	ans++;
	subs(inp,out,i+1,j+1);
	
}
int main() 
{
	char inp[1000];
	cin>>inp;
	char out[1000];
	subs(inp,out,0,0);
	cout<<endl;
	ans+=1;
	cout<<ans<<endl;
	return 0;
}
