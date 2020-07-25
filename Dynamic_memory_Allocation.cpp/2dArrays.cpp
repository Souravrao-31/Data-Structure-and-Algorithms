#include<iostream>

using namespace std;


int main(){

    int **arr;
    int r,c;

    cin>>r>>c;

    //create an array of row heads
    arr= new int*[r];

    //create an 2d array
    for(int i=0;i<r;i++){
        arr[i] = new int[c];
    }

    //take input an print the elements
    int val = 1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j] = val;
            val++;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}