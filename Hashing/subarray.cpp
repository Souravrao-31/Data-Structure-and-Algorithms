 #include<bits/stdc++.h>
 using namespace std;
 
 int subarraySum(vector<int>& nums, int k) {
        int sum = 0 ;
        map<int,int> m;
        m[0] = 1;
        int ans = 0;
        for( int i = 0 ; i < nums.size();i++)
        {
            sum+=nums[i];
            if(m.find(sum-k) != m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }

    int main(){
        vector<int> nums;
        int n;cin>>n;
        for(int i=0;i<n;i++){
           int x;cin>>x;
           nums.push_back(x);
        }
        cout<<subarraySum(nums,0);

        return 0;
    }