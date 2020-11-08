#include<iostream>
using namespace std;

float Square_root(int n,int p){

    long long int ans = -1;
        
    int s = 0;
    int e = n - 1;
    long long int mid;


   if(n==0) return 0;
   if(n==1) return 1;
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
        else
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

class Solution {
public:
    int mySqrt(int x) {
         
        	if (x < 2) return x;
		
		uint64_t mult = 0;
		int count = 0;
		
		//have mult start with half the bits of the other, if that's 0 or odd, then +1 bits
		while ((x >> (31 - count) & 1u) == 0) count++;
		count = (32 - count)/2 - ((count+1) % 2);
		
		//set all mult bits to 1 from count to beginning
		mult |= (~(0u) >> (31 - count));

		//while mult is greater, set smaller bits to 0
		while (mult * mult > x && count > 0) {
			count--;
			mult ^= (1u << count);
			
			//mult^2 is less than x but has too large of a difference, reset bit back to 1
			if (mult * mult + (mult * 2) < x) mult |= (1u << count);
		}
		return mult;
        
        
    }
};
int main(){
    
    int n;
    cin>>n;
    cout<<Square_root(n,5);
    
    return 0;
}