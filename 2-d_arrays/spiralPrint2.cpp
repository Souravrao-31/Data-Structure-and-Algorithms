#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(); //For Row
        
        if(n==0)   return {};
          
		vector<int> arr;
        int m=matrix[0].size();  //for Col 
        
        if(n==1){
            for(int i=0;i<m;i++){
                arr.push_back(matrix[0][i]);                
            }
            return arr;
        }
        if(m==1){
            for(int i=0;i<n;i++){
                arr.push_back(matrix[i][0]);                
            }
            return arr;
        }
        int top=0,left=0,right=m-1,bottom=n-1;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                arr.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                arr.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--)
                    arr.push_back(matrix[i][left]);
                left++;
            }
        }
        return arr;
    }
};


int main(){


    vector<vector<int>> matrix;
  
    int N,M; cin>>N>>M;

   
    for(int i=0;i<N;i++){
        vector<int> row;
        for(int j=0;j<M;j++){
          int x;
          cin>>x;
          row.push_back(x);
        }
        matrix.push_back(row);
    }

    Solution s;
   vector<int> mat;
    mat = s.spiralOrder(matrix);
    cout<<endl;
    for(int i=0;i<N*M;i++){
       cout <<mat[i]<<" ";
    }

    return 0;
}