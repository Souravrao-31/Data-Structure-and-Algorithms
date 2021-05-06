#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define MIN                   -1e9 
#define itoc(c)               ((char)(((int)'0')+c)) 
#define vi                    vector<int> 
#define vvi                   vector<vi> 
#define pll                   pair<ll,ll> 
#define pii                   pair<int,int> 
#define all(p)                p.begin(),p.end() 
#define max(x,y)              (x>y)?x:y 
#define mid(s,e)              (s+(e-s)/2) 
using namespace std;

void evegame(){
   
 ll n;
 cin>>n;

 ll t, o = 0 , e =0,i;

 for(i=0;i<n;i++){
   cin>>t;
   if(t%2 ==1) o++;
   else e++;
 }
 cout<<min(o,e)<<'\n';

}

int main(){

    ll t;
    cin>>t;

    while (t--)
    {
        evegame();
    }
    
}