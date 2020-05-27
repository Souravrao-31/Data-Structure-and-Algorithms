#include<iostream>
using namespace std;

int f(int N,int C,int *weight,int *prices){
    //base case
    if(N==0 || C==0){
       return 0;
    }
    //rec case
    int ans=0;
    int inc,exc;

    inc = exc = 0;
   
    //inc
    if(weight[N-1] <= C){
        inc = prices[N-1] + f(N-1,C - weight[N-1],weight,prices);
    }
    //exc
    exc= f(N-1,C,weight,prices);

    ans =max(inc,exc);
    return ans;
}

int main(){
    int weight[] ={1,2,3,5};
    int prices[] ={40,20,30,100};

    int N=4;
    int C=7;  //capacity

    cout<<f(N,C,weight,prices);

    return 0;
}