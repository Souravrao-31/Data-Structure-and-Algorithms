#include <iostream>
#include <unordered_set>
using namespace std;
/*
One of the best approach.
O(n) 
6
10 3 20 1 2 4
4
*/
int LongestConsecutiveSequence(int *arr,int n){
    unordered_set<int> s;
    for(int i=0;i<n;i++){
       s.insert(arr[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i] - 1)  != s.end()){
            continue;
        }
        else{
            int count = 0;
            int x = arr[i]; //Left Boundary
            while(s.find(x) != s.end()){
                count++;
                x++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = LongestConsecutiveSequence(arr,n);
    cout<<ans<<endl;
    return 0;
}