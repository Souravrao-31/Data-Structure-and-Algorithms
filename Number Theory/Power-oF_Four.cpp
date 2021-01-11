#include<iostream>
using namespace std;

//Leetcode 342
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        while(n>1){
            if(n % 4) return false;
            n/=4;
        }
        return true;
              
    }
};

int main(){

    int n;cin>>n;

    Solution   S1;
    
    cout<<S1.isPowerOfFour(n)<<endl;

}