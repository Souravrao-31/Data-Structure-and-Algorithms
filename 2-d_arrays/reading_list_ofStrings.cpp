#include<iostream>
using namespace std;

int main(){
    char a[100][1000];
    int n;
    cin>>n;

    cin.get();

    for(int i=0;i<n;i++){
        cin.getline(a[i], 1000);
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}