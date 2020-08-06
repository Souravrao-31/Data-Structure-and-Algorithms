#include <iostream>
#include <stack>
#include<vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) 
{
        int i=0, n=heights.size(), mx=0, ht;
        stack<int> s;
        while(i<n){
            if(s.empty() || heights[s.top()]<=heights[i])
                s.push(i);
            else{
                while(!s.empty() && heights[s.top()]>heights[i]){
                    ht=heights[s.top()];
                    s.pop();
                    if(!s.empty()){
                        mx=max(mx, (i-s.top()-1)*ht);
                        cout<<"if---"<<mx<<endl;
                    }
                    else{
                        mx=max(mx, i*ht);
                        cout<<"else---"<<mx<<endl;
                    }
                }
                s.push(i);
            }
            i++;
        }
        while(!s.empty()){
            cout<<s.top();
            cout<<endl;
            s.pop();
        }
        while(!s.empty()){
            ht=heights[s.top()];
            s.pop();
            if(!s.empty()){mx=max(mx, (i-s.top()-1)*ht);
                cout<<"if-"<<mx<<endl;}
                
            else
                {
                    mx=max(mx, i*ht);
                    cout<<"else-"<<mx;
                }
        }
        return mx;
}

int main() {
    int n;
    cin>>n;
    vector<int> heights;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        heights.push_back(a);
    }
    cout<<largestRectangleArea(heights);
    return 0;
}



/*
Algorithm:
To find the area of the largest rectangle from the given heights, we first iterate through the vector of heights. 
We find the one which is taller than its adjacent bars and check if it is giving the max area. 
We compare the already max area stored in mx and the area we found. 
The max between both stays in mx, and is returned at the end.
While iterating through the vector, if the height is not taller than its neighbours, or the stack is empty then we push the index of this height in the stack.
If it is tall than the next height and the stack is also not empty,
then we check all the possible areas that can be formed from this height,
that means we check all possible heights till the stack is empty and store the max height in the variable mx. 
 At the end we return mx.
After the iteration is complete we repeat the process of checking all possible areas again. This is for the last bar. We check all possible areas from the last bar, till the stack is empty.

Time Complexity:
The time complexity of the above code is O(n), where n is the size of the vector of the given heights.
*/