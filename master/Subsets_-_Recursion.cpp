// @author: Abhimanyu Maurya


#include <iostream>
#include<cstring>
#include<vector>
using namespace std;


//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

// define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif

vector<string> res;

void allSubsets(int a[],int n,int p,int sum,int k,string out)
{
    if(sum==k) 
    {
        res.push_back(out);
        return;
    }

    if(p>=n) return;
    char ch[2] = {a[p] + '0','\0'};
    allSubsets(a,n,p+1,sum+a[p],k,out+ch);
    allSubsets(a, n, p + 1, sum, k, out);
}

int main()
{
    int n,k,a[25];
    cin>>n;
    string out;

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>k;
    allSubsets(a,n,0,0,k,out);
    for (auto i = res.rbegin(); i <res.rend(); i++)
    {
        for (auto j = (*i).crbegin() ; j < (*i).rend(); j++)
        {
            cout<<*j<<" ";
        }
        cout<<"\n";
    } 
}
