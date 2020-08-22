#include <bits/stdc++.h>
using namespace std;

/*
Input Format
First line contains an integer n denoting the size of the array.
Second line contains n space separated integers denoting array elements.
Third line contains single integer Q denoting the no of queries.
Q lines follow , each containing a single integer x that is to be searched in the array.

Constraints
1 <= N <= 10^5
1 <= Q <= 100

Output Format
For each query , print the lowerbound and the upperbound for the number x in a new line each.

Sample Input
5
1 2 3 3 4
3
2
3
10
Sample Output
1 1
2 3
-1 -1
*/


  int upper_bound(int a[],int n,int key)
  {
      int s=0;
      int e=n-1;
       int ans=-1;

      while(s<=e)
      {
          int mid=(s+e)/2;
      
      if(a[mid]==key)
      {
          ans=mid;
          s=mid+1;      //change

      }
      else if (a[mid]>key)
      {
          e=mid-1;

      }
         else{
         
         s=mid+1;
         }
  }
   return ans;

}


 int lower_bound(int a[],int n,int key)
  {
      int s=0;
      int e=n-1;
       int ans=-1;

      while(s<=e)
      {
          int mid=(s+e)/2;
      
      if(a[mid]==key)
      {
          ans=mid;
          e=mid-1;  //change

      }
      else if(a[mid]>key)
      {
          e=mid-1;

      }
         else{
         
         s=mid+1;
         }
  }
   return ans;

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   int t;
   cin>>t;
   while(t--)
   {
    int key;
    cin>>key;
   
   int ans = lower_bound(a,n,key); //first calculate lower_bound
   cout<<ans<<" ";
    ans= upper_bound(a,n,key);  //then calculate upper_bound
   cout<<ans;
   cout<<endl;
   ans=0;
   }
   return 0;

}
