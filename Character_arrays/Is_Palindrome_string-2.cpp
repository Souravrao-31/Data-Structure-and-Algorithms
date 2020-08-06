#include<iostream>
using namespace std;

/*Leetcode 125
Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
*/
//Two pointer method O(n) O(1)
class Solution{
    public:
       bool palindrome(string s){
         int i=0;
         int n=s.length();
         int j=n-1;
        
        if(n==0) return true;
        
        while(i<=j){
            //
        while(i<j && !isalnum(s[i])){
            i++;
        }
          while(i<j && !isalnum(s[j])){
            j--;
        }

        if(tolower(s[i]) == tolower(s[j]) ){
            i++;
            j--;
        }  
        else {
            return false;
            }
       } 
       return true;
    }
};

int main(){
    string s;
    getline(cin,s);
  Solution S;
  if(S.palindrome(s)) cout<<"True";
  else cout<<"false";
}