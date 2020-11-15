#include<iostream>
#include<vector>
#include<deque>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int i, sum, carry = 1;
        for(i = digits.size()-1; i>=0; i--)
        {
            sum = digits[i] + carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        
        if(carry == 0) return digits;
        
        deque<int> deq;
        while(carry!=0)
        {
            deq.push_front(carry%10);
            carry /= 10;
        }
        vector<int> ans;
        while(deq.size()>0)
        {
            ans.push_back(deq.front());
            deq.pop_front();
        }
        for(i=0;i<digits.size();i++)
            ans.push_back(digits[i]);
        return ans;
        
        
    }
};


int main(){
    int n;cin>>n;

    vector<int> digits;

    for(int i=0;i<n;i++){
      int x; cin>>x;
      digits.push_back(x);
    }
    Solution s;
    

    vector<int> temp;
    temp = s.plusOne(digits);

    for(auto cp:temp){
        cout<<cp<<" ";
    }
    return 0;
}