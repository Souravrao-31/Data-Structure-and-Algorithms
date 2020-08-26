#include<iostream>
#include<vector>
using namespace  std;
class Search{
    public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        
      if(!matrix.size()) return false;
       int r = matrix.size();
       int c = matrix[0].size();

       int low =0;
       int high = (r*c) -1;

        while(low <= high){
           int mid = (low + ( high - low) / 2);
           if(matrix[mid/c][mid%c] == target){
                return true;
           }
           if(matrix[mid/c][mid%c] < target){
               low = mid +1;
           }
           else{
               high = mid -1;
           }
     
       }
       return false;
     
     
    }
    bool search_matrix(vector<vector<int>> &matrix, int target){
        int row= matrix.size();
        if(row==0)
            return 0;
        
        int col= matrix[0].size();
		
        int r=0 , c=col-1 ;
        
        while(c>=0 && r<row){
            
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c] > target)
                c--;
            else
                r++;
            
        }
        return false;
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
    int target;cin>>target;

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //     cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
     
      Search s;
      if(s.searchMatrix(matrix, target)) cout<<"yes present";
      else cout<<"No";
    

    return 0;
}