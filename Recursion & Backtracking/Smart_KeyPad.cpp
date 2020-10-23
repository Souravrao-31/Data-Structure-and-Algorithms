#include<iostream>
using namespace std;

void phone_keypad(char inp[],char out[],char table[][10],int i,int j)
{
	if(inp[i]=='\0')
	{
		out[j]='\0';
		cout<<out;
		cout<<endl;
		return;
	}


	int digit=inp[i]-'0';

	for(int k=0;table[digit][k]!='\0';k++)
	{
		out[j]=table[digit][k];
		phone_keypad(inp,out,table,i+1,j+1);
	}
}


int main() {


	char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	char inp[100];
	cin>>inp;

	char out[100]="";

	phone_keypad(inp,out,table,0,0);

	return 0;
}