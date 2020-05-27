#include <iostream>
using namespace std;

bool canPlacecows(int stalls[],int n,int c,int min_sep){

int last_cow = stalls[0];
//place the first cow in the first stall
int cnt=1;

for(int i=1;i<n;i++){
    if (stalls[i]-last_cow >= min_sep)
    {
        last_cow =stalls[i];
        cnt++;
        if (cnt==c)
        {
            return true;
        }
        
    }
    

}
 return false;

}

int main()
{
     //Problem : Aggressive cows(Spoj.com)
     //here n is no. of stalls
     int stalls[] ={1,2,4,8,9};
     int n=5;

     int cows=3;


     int s=0;
     int e =stalls[n-1] - stalls[0];

     int ans=0;

     while (s <= e)
     {
         int mid =(s+e)/2;

         bool cowsRakhPaye = canPlacecows(stalls,n,cows,mid);
         if (cowsRakhPaye)
         {
            ans=mid;
            s=mid+1;
        
         }
         else{
             e=mid-1;
         }


     }
     cout<<ans<<endl;
     

    return 0;
}