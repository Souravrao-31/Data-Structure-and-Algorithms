#include <iostream>

using namespace std;

bool Is_Palindrome(int arr[],int n){
	int start=0;
	int end=n-1;
	while(start<=end){
		if(arr[start]==arr[end]){
			start++;
			end--;
		}else{
			return false;
		}
	}return true;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(Is_Palindrome(arr,n)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}