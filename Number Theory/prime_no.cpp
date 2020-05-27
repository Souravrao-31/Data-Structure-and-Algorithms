#include <iostream>
using namespace std;
#define ll long long
//naive approach
bool primeno(int n){     // O(srqrt N)
 if (n == 1)
 {
     return false;
 }
 
 for (int i = 2; i * i <= n; i++)           //when if i<n its a naive method O(N)
 {
    if (n % i ==0)
    {
        return false;
    }
    
 }
    return true;

}
/*
To find nUmber till N.
More optimised method is a prime seive.
*/
int main(){
    int n;
    cin>>n;

    if (primeno(n))
    {
        cout<<n<<"is prime no";
    }
    else
    {
        cout<<"not a prime no";
    }
    

    return 0;
}