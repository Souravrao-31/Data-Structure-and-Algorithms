#include<iostream>
using namespace std;


//Leetcode 326
class Solution{
    public:
        bool isPowerOfThree(int n){
            return ((n > 0) && (1162261467 % n == 0));  // 3^19, largest int
        }
};

class Solution_2{
    public:
        bool isPowerOfThree(int n){
            if(n <= 0){return false;}
            while(n > 1){
                if(n % 3 > 0){return false;}
                n /= 3;
            }
            return true;
        }
};

int main(){

    int n;cin>>n;

    Solution   S1;
    Solution_2 S2;
 
    cout<<S1.isPowerOfThree(n)<<endl;
    cout<<S2.isPowerOfThree(n);

}