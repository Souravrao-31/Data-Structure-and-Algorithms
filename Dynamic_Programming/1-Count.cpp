#include<iostream>
using namespace std;

/*
Given an array of size n with 0s and 1s , flip at most k 0s to get the longest possible subarray of 1s.

Input Format
First Line : n, size of array and k Second Line : n space separated numbers (0s or 1s)

Constraints
n <= 10^5 0 <= k <= n

Output Format
First Line : Size of subarray Second Line : Array after flipping k 0s

Sample Input
10 2
1 0 0 1 0 1 0 1 0 1
Sample Output
5
1 0 0 1 1 1 1 1 0 1
*/


int count(int* arr, int n , int k){
  int l=0,r=0;
  int count0=0;
  int best=0;
  int i=0,j=0;
  if(n==1 and arr[0]==1){
	  return 1;
  }
  if(n==1 and arr[0]==0){
	  return 0;
  }
  for(int r=0;r<n;r++){
	  if(arr[r]==0){
		  count0++;
	  }
	  while(count0>k){
		  if(arr[l]==0){
			  count0--;
		  }
		  l++;
	  }
      if(r-l+1>best){
	  best=max(best,r-l+1);
      i=l;
      j=r;
    }
  }  
  for(i;i<=j;i++){
      arr[i]=1;
  }
  return best;
}
int main() {
	int n,k;
	cin>>n>>k;
	int * arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(k==0){
		int mxlen=0,templen=0;
		for(int i=0;i<n;i++){
			if(arr[i])
			   templen++;
			else
			   templen=0;
			 mxlen=max(mxlen,templen);     
		}
		cout<<mxlen<<"\n";
		for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
        }
		return 0;
	}
	cout<<count(arr,n,k)<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}