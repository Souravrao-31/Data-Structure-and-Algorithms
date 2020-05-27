#include <iostream>
using namespace std;

void readmatrix(int a[][100],int R,int C){
     
     for (int i = 0; i < R; i++)
     {
         for (int j = 0; j < C; j++)
         {
         	cin>>a[i][j];

         }
     }
      
}

void printmatrix(int a[][100],int R,int C){
    for (int i = 0; i < R; i++)
     {
         for (int j = 0; j < C; j++)
         {
         	cout<<a[i][j]<<" ";

         }
         cout<<endl;
     }
}
int main()
{
	int a[100][100];
	int R;
	int C;
	cin>>R>>C;
	readmatrix(a,R,C);
    printmatrix(a,R,C);

	return 0;
}