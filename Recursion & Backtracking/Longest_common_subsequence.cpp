#include<iostream>
#include<math.h>
using namespace std;

class Solution{

public:
    int LongestSubsequence(string s1, string s2){
           return Recursive(s1,s2,0,0);
    }   

    int Recursive(string s1, string s2, int i,int j){
       
       if(i> s1.length() - 1 || j>s2.length()-1) return 0;
       
      
        
       if(s1.at(i) == s2.at(j)){
            return 1 + Recursive(s1,s2,i+1,j+1);
       }  
       else{
             return max(  Recursive(s1,s2,i,j+1),
               Recursive(s1,s2,i+1,j) );
            
       }

    }


};
/*
leetcode 1143
this sol will work
but due to repeated  value by  recursion will increase the time complexity
So, to optimise this solution Dp is used 
So please check dp solution
*/
int main(){
    string s1,s2;
    cin>>s1>>s2;
    Solution sol;
   cout<< sol.LongestSubsequence(s1,s2);

    return 0;

}