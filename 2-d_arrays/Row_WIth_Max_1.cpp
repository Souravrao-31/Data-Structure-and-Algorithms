#include<iostream>
#include<vector>
using namespace  std;



/*
i/p
4 4
0 0 1 1
1 1 1 1
0 0 0 1
0 1 1 1
o/p
1
*/
class Solution {

public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int res=-1;
        for(int col=0;col<m;col++){
            for(int row=0;row<n;row++){
                if(arr[row][col] == 1){
                    return row;
                }
            }
        }
        return res;
    }

        //Approach 2
    int rowWithMax1s_2(vector<vector<int> > arr, int n, int m) 
    {
        int j = m-1;
        while(j>=0 && arr[0][j]==1)
        {
            j--;
        }
        int row = 0;
        
        for(int i=1;i<n;i++){
            
            while(j>=0 && arr[i][j]==1){
                j--;
                row = i;
            }
        }
        return j==m-1 ? -1 : row;
        
    }

};

int main(){
int N,M;
cin>>N>>M;

    vector<vector<int>> matrix;

    for(int i=0;i<N;i++){
        vector<int> row;
        for(int j=0;j<M;j++){
            int x;
            cin>>x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //     cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
        // }
    Solution S;
    //cout<<S.rowWithMax1s(matrix, N,M);
    cout<<S.rowWithMax1s_2(matrix, N,M);
    

    return 0;
}