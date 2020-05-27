#include<iostream>
using namespace std;

float Square_root(int n,int p){

    int s = 0;
    int e = n - 1;
    int mid;
    float ans = -1;


    while (s <= e)
    {
        mid = (s + e) / 2;

        if (mid*mid ==n)\
        {
            return mid;
        }

        if(mid*mid < n){
            ans=mid;
            s=mid+1;
        }
        else..
        {
            e=mid-1;
        }
        
    }
    //floating part
    //naive sol

    float inc=0.1;
    //p is the decimal precision
    for (int i = 1; i <= p; i++)
    {
        while(ans*ans <= n ){
            ans = ans +inc;
        }
        //overshot the value
        ans = ans - inc;
        inc=inc/10;
    }
    
   return ans;

}
int main(){
    
    int n;
    cin>>n;
    cout<<Square_root(n,5);
    
    return 0;
}