#include <iostream>
#include <algorithm>
using namespace std;

int compare(int a,int b){
	return a<b;
}
void targetsum(int *arr,int n,int target){

	sort(arr,arr+n,compare);

	int left=0;
	int right=n-1;

	while(left<right){
		int sum=arr[left] + arr[right];
		if (sum>target)
		{
			right--;
		}
		else if(sum<target){
			left++;
		}
		else{
			cout<<arr[left]<<" and "<<arr[right]<<endl;

			left++;
            right--;

		}
	}
}
int main()
{
	

	int target;
    int n;

	cin>>n;

	int arr[10000];

	for (int i = 0; i < n;i++)
	{
	    cin>>arr[i];
	}
    cin>>target;
	targetsum(arr,n,target);

	return 0;
}
