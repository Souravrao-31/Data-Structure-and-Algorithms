#include <iostream>
using namespace std;
int main()
{
	int **arr=new int*[3];   //it will create the primary array in the heap area
	for (int i = 0; i < 3; ++i)
	{
		arr[i]=new int [4];  //secondary array
	}

	int counter=0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j]=counter;
			counter++;
		}
	}
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	for (int i = 0; i < 3; ++i)
	{
		delete [] arr[i];
	}
   delete [] arr;
   cout<<"hello";
	return 0;
}