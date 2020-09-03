#include<iostream>
using namespace std;

//leetcode 91
class Solution {
public:
    int numDecodings(string s) {
        
        if(s.length() == 0 || s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        int count1=1,count2=1 ;
        
        for(int i=1;i<s.length();i++){
       
             int d = s[i] - '0';
             int dd = (s[i-1] - '0')*10 +d;
            
             int count =0;
          
             if(d>0) count += count2;
            
             if(dd >= 10 && dd <= 26) count += count1;
           
            
            //cout<<count<<" "<<count2<<" "<<count1<<endl;
             count1 = count2;
             count2 = count;
             
            
        }
        
        return count2;
        
    }
};

int main(){
  
  string s;
  cin>>s;
   Solution sol;
   cout<<sol.numDecodings(s); //12120
    return 0;
}