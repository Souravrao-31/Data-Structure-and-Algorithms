#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
ios::sync_with_stdio(0); 
cin.tie(0);
int x,y;
for(int i = 1 ; i <= 5 ; i++){
    for (int j = 1; j <=5; j++)
    {
        int a;
        cin>>a;
        if(a==1){
            x = i;
            y = j;
        }
    }
}
    x = (3 - x);
    y = (3 - y);
    x=abs(x);
    y=abs(y);
    cout<<x+y;
    return 0;
}