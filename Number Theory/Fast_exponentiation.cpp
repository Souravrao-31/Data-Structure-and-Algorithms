#include <iostream>
using namespace std;

/*
Through bitmsaking we can find the exponent power
in O(Logn) time complexity

a=2 b=5     2*2*2*2*2
o/p =32
*/
int fun(int a,int n){ // this does'nt solve every test cases
  
    int ans=1;

    while(n>0){
     int last_bit =(n&1);
     //cout<<" last-bit "<<last_bit<<endl;
        if(last_bit){
        ans = ans * a;

        }
    a = a*a;
    n = n>>1;

    }
   return ans;
}
 double myPow(double x, int n) {
        
        double ans = 1;
        
        while(n>0){
            int lastbit = (n&1);
            
            if(lastbit){
                ans = ans *x;
            }
            x =x *x;
            n = n>>1;
        
        }
        return ans;
        
}
  double myPow_2(double x, int n) {
          double ans =1.0;
        long long num = n;
        if(num<0) num =-1*num;
        
        while(num){
             if(num %2){
                 ans = ans *x;
                 num = num -1;
             }
            else{
                x = x*x;
                num = num/2;
            }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
        
        
    }

int main(){
    
    double a;
    int n;
    cin>>a>>n;

    //cout<<fun(a,n);
    cout<<myPow(a,n);
    return 0;
}