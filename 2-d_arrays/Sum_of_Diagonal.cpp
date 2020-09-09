#include<iostream>
#include<vector>
using namespace  std;

/*
3 3
1 2 3
4 5 6
7 8 9
15

for even u dont have to del midle bcoz its not intersection of other
4 4
1 2 2 3
4 5 6 8
10 2 3 8
1 2 3 4
25

*/
class Sum{

public:
       //O(2N)
    int diagonalSum(vector<vector<int>> &mat){
        int n=mat.size();
        int sum=0;

        for(int i=0;i<n;i++){
           sum += mat[i][i] + mat[i][n-i-1];        
        }
        if(n%2) sum -= mat[n/2][n/2];
        return sum;
    } 
};


int main(){
    int N;
    cin>>N>>N;

    vector<vector<int>> matrix;

    for(int i=0;i<N;i++){
        vector<int> row;
        for(int j=0;j<N;j++){
          int x;
          cin>>x;
          row.push_back(x);
        }
        matrix.push_back(row);
    }
    Sum s;
    cout<<s.diagonalSum(matrix);
    return 0;
}