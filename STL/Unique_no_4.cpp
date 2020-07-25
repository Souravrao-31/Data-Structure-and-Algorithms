#include<bits/stdc++.h>
using namespace std;

/*
9
1 2 3 4 1 2 4 3 5
5
*/
int single_number(int arr[], int sz)
{
   map<int, int> hmp;  
   map<int, int>::iterator it;
   int number = 0;
   for(int i=0; i<sz; i++) 
   {   /*iterate through array and populate count for each array element */
        it = hmp.find(arr[i]);
        if(it != hmp.end())
            it->second += 1;
         else
            hmp.insert(pair<int,int>(arr[i], 1));
    }
    for(int i=0; i<sz; i++) 
    { /* iterate Hashtable and find one array element where count = 1; */
        it = hmp.find(arr[i]);
        if(it->second == 1)
            return arr[i];
    }
    return 0;
}

int main()
{   int n;cin>>n;
    int arr[100000];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<single_number(arr,n);

    return 0;
}