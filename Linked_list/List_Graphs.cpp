#include<iostream>
#include<list>
using namespace std;
/*
i/p

3 3
0 1 4
0 2 3
1 2 4

3 4
0 1 4
0 2 3
1 2 4
0 9 8
*/
int main(){

    //List to create Graph DS
    list<pair<int,int> > *l;
    int n;
    cin>>n;

    l = new list<pair<int,int> >[n];
    int e;
    cin>>e;
    
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }
    //Print
   
    for(int i=0;i<n;i++){
        cout << "Linked list " << i << "->";
        for (auto xp : l[i])
        {
            cout << "(" << xp.first << "," << xp.second << "),";
       }
       cout<<endl;
    }

    
    return 0;
}