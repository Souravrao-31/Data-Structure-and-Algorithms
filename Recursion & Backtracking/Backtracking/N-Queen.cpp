#include <iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n){
      //You can check for col
      for(int row=0;row<i;row++){
          if(board[row][j]==1){
            return false;
        }

      }

      // you can check for Left Diagonal
      int x=i;
      int y=j;

      while(x >= 0 && y >= 0){
          if(board[x][y]==1){
            return false;
          }
          x--;
          y--;
        }

        //You can check for right diagonal

         x = i;
         y = j;

        while (x >= 0 && y < n)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            x--;
            y++;
        }
        //The position is now safe col and diagonal
        return true;

}

bool solveNQueen(int board[][10],int i,int n){
 //base case
    if(i==n){
   //u have successfully place the queens in n rows ( 0......n-1)
   //print the board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(board[i][j] == 1){
                cout<<"Q ";
               }
               else{
               cout<<"_ ";
             }
         }
          cout<<endl;
   }
   return true;

 }

 //Recursive case
  //try to place queen in the row and call on thr remaining part which will be solve by recursive
 for(int j=0;j<n;j++){
   //I have to check the i,j position its safe to place queen or not
    if(isSafe(board,i,j,n)){
        //Place the queen -Assuming i,j is the right position
        board[i][j] = 1 ;

        bool nextQueenRakhPaaRheHain = solveNQueen(board,i+1,n);
        if(nextQueenRakhPaaRheHain){
            return true;
        }
        //It means i,j is not the right position
        board[i][j] = 0; //backtrack
    }
 }

   //u Have tried for all positions in the current
   return false;

}

int main(){

  int n;
  cin>>n;

  int board[10][10] = {0};

  solveNQueen(board,0,n);

    return 0;

}