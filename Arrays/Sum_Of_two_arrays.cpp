#include<bits/stdc++.h>
using namespace std;
int main() {
	//cins
	int n;
	cin>>n;
	int a[n];
	long long int suma = 0,sumb=0;

	for(int i=0;i<n;i++){
		cin>>a[i];
		suma += (a[i]*pow(10,n-i-1));
	}

	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
		sumb += (b[i]*pow(10,m-i-1));
	}
	

	//logic
	long long int resSum = suma+sumb;
	long long int temp = resSum;
	// cout<<resSum<<endl;
	int count = 0;
	while(resSum!=0){
		resSum/=10;
		count++;
	}
	resSum=temp;
	// cout<<count<<endl;
	int resArr[count];
	for(int i=0;i<count;i++){
		resArr[i] = resSum%10;
		resSum = resSum/10;
	}
	reverse(resArr,resArr+count);
	for(int i=0;i<count;i++){
		cout<<resArr[i]<<", ";
	}
	cout<<"END";
	
	
}