#include <iostream>
using namespace std;

void spiralprint(int a[][100],int C,int R ){
    
    int startRow = 0;
    int startCol = 0;
    int endCol = C - 1;
    int endRow = R - 1;

    while(startRow<=endRow and startCol<=endCol){
         
         for(int i=startCol;i<=endCol;i++){        /// ----------->
             cout<<a[startRow][i]<<" ";
         }
        startRow++;

        for(int i=startRow;i<=endRow;i++){           
                                                          
            cout << a[i][endCol] << " ";
        }  
        endCol--;
       
        if(endRow >= startRow){
            for(int i=endCol;i>=startCol;i--){
                cout<<a[endRow][i]<<" ";
            }
            endRow--;
        }

        if(endCol >= startCol){
            for(int i=endRow;i>=startRow;i--){
                cout<<a[i][startCol]<<" ";
            }
            startCol++;
        }
    }


}


int main(){

    int R,C;
    cin>>R>>C;
   int a[100][100];
   int temp = 1;
   for (int i = 0; i < R; i++)
   {
       for (int j = 0; j < C; j++)
       {
           a[i][j] =temp;
           temp +=1;
           cout << a[i][j]<<" ";
       }
       cout<<endl;
        
    }
    
    spiralprint(a,R,C);
    return 0;
}