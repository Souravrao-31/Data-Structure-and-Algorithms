#include<iostream>
#include<vector>

using namespace std;

#define ll long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M = 22;
int vis[N];
bool odd_cycle = 0;
vector<int> gr[N];


void dfs(int cur, int par,int col){
    vis[cur] = col;
       for(auto child : gr[cur]){
           if(vis[child] == 0){
              dfs(child, cur, 3 - col);
           }
           else if(child != par && col == vis[child]){
                //backedge and odd length cycle
                odd_cycle = 1;
           }
       }
       return;
}

void solve(){
    int i,j,k,n,m, ans=0, cnt=0, sum=0;
    cin>>n>>m;
    for(i =0;i<m;i++){
       int x,y;
       cin>>x>>y;
       gr[x].pb(y);
       gr[y].pb(x);
    }
    dfs(1, 0, 1);
    if(odd_cycle) {cout<<"Not Bipartite";}
    else {cout<<"Bipartite";}
}

/*
5 5
1 2 
2 3 
3 1 
3 4 
4 5 
Not Bipartite

4 4 
1 2 
2 3 
3 4 
1 4 
Bipartite
*/

int main()
{
    solve();
    
}