#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const vector<pair<int, string>> conv = {{1000, "M"},
                                            {900, "CM"},
                                            {500, "D"},
                                            {400, "CD"},
                                            {100, "C"},
                                            {90, "XC"},
                                            {50, "L"},
                                            {40, "XL"},
                                            {10, "X"},
                                            {9, "IX"},
                                            {5, "V"},
                                            {4, "IV"},
                                            {1, "I"}};
public:
    string intToRoman(int num) {
        string res;
        auto it = conv.begin();
        while (num > 0 && it != conv.end()) {
            if (num >= it->first) {
                num -= it->first;
                res += it->second;
            } else {
                ++it;
            }
        }
        return res;
    }
 
    string intToRoman_II(int num) {
        
        if(num==0) return "";     
        
        if(num==9) return "IX"+intToRoman(num-9);
        if(num==4) return "IV"+intToRoman(num-4);
        if(num>=40&&num<50) return "XL"+intToRoman(num-40);
        if(num>=90&&num<100) return "XC"+intToRoman(num-90);
        if(num>=400&&num<500) return "CD"+intToRoman(num-400);
        if(num>=900&&num<1000) return "CM"+intToRoman(num-900);
        
        if(num<=3) return "I"+intToRoman(num-1);     
        if(num<10) return "V"+intToRoman(num-5);
        if(num<40) return "X"+intToRoman(num-10);
        if(num<100) return "L"+intToRoman(num-50);     
        if(num<400) return "C"+intToRoman(num-100);     
        if(num<1000) return "D"+intToRoman(num-500);     
        if(num>=1000) return "M"+intToRoman(num-1000);
        return "";
    }
    

};

int main(){
    Solution s;
    
     int n;cin>>n;
     //cout<<s.intToRoman(n);
     //cout<<s.intToRoman_II(n);
    return 0;
}