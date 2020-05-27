#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Queue{
 int *arr;
 int f,r,ms,cs;
 public:
   Queue(int n){
       arr=new int [n];
       cs=0;
       ms=n;
       f=0;
       r=n-1;
   }

    void push(int data){
       if(cs==ms){
         return;
       }
       r=(r+1)/ms;
       arr[r] =data;
       cs++;
    }
    void pop(){
        if(cs==0) return;
        f =(f+1) % ms;
        cs--;
    }
    bool empty(){
        return cs==0;
    }
    bool full(){
        return cs==ms;
    }
    int front(){
        return arr[f];
    }
    int size(){
       return cs;
    }
};




int main(){
 
 return 0;
}