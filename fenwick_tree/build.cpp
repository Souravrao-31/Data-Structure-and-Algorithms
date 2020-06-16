/*
steps ->0   = number of set bits.
child -> parent   remove last bit.

*/
#include<bits/stdc++.h>
using namespace std;

struct fenwick{
    vector<int > f;
    int n;
    void init(int n){
        this->n =n+1;
        f.resize(n+1,0);
    }
    //return sum of preix  -[1,x]
    int sum(int x){
        x++;
        int ans=0;
        while(x>0){
          ans+=f[x];
          x=x-(x & -x);
        }
        return ans;
    }
    int add(int index,int val){
        index++;
        while(index < n){
            f[index] += val;
            index = index + (index & -index);
        }
    }
    int sum(int l,int r){
        return sum(r)-sum(l-1);
    }

};

int main(){
    int n;
    cin>>n;
    int a[n];
    fenwick bit;
    bit.init(n);
    for(int i=0;i<n;i++){
       cin>>a[i];
       bit.add(i,a[i]);
    }
    cout<<bit.sum(0)<<'\n';
    cout << bit.sum(3) << '\n';
    cout << bit.sum(4) << '\n';
    cout << bit.sum(0,4) << '\n';
    cout << bit.sum(2, 4) << '\n';
    return 0;
}