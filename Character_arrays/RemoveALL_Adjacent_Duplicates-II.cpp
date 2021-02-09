#include <iostream>
#include <stack>
#include <vector>
using namespace std;


/*
1209

Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique
*/
class Solution
{
public:
    string Hash_table(string s,int k)
    {
    
       vector<int> vec(s.length(), 0);
       int i = 0;

       while(i < s.length()){
          
            if(i ==0 || s[i] != s[i-1]){
                vec[i] = 1;
            }
        
            else{
                vec[i] = vec[i-1] + 1;
                    if(vec[i] == k){
                        i -= k;
                        s.erase(i+1,k);
                }

            }
            i++;
       }

       return s;
       
    }



    //Second Approach

    string Stack_implem(string s,int k){
         stack<pair<char,int>> st;
        for(auto it:s){
            if(st.empty())
                st.push({it,1});
            else{
                auto j=st.top();
                if(j.first==it){
                    if(j.second==k-1)
                        st.pop();
                    else
                    {
                        pair<char,int> w={j.first,j.second+1};
                        st.pop();
                        st.push(w);
                    }
                }
                else{
                    st.push({it,1});
                }
            }
        }
        string ans="";
        while(st.size()!=0){
            int no=st.top().second;
            while(no--)
                ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};

int main()
{
    string S;
    cin>>S;
    int k;cin>>k;

    Solution s;
    cout<<s.Hash_table(S,k);
    //cout<<s.Stack_implem(S,k);
    return 0;
}