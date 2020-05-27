#include <iostream>
using namespace std;
int main() {
    int a[10];
    int n;
    cin>>n;
    int i;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        {
           cout<<"found at index "<<i<<endl;
           break;
        }  
    }
    if(i==n)
    {
    cout<<"Not found";
    }
    return 0;
}
