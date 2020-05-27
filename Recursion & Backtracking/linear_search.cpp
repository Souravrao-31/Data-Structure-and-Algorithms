#include <iostream>
using namespace std;

int linearsearch(int *a,int i,int n,int key){
if(i == n){
    return -1;
}
if(a[i]==key){
    return i;
}
return linearsearch(a,i+1,n,key);

}
int main(){
    int a[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int key;
    cin>>key;
    cout<<linearsearch(a,0,n,key);
    return 0;
}