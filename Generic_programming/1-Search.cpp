#include<iostream>
#include<cstring>
#include<list>
using namespace std;


template<typename T>  //or template<class T>
int Search(T arr[],int n,T key){
    
    for(int i=0;i<n;i++){
        if(arr[i]==key){
        return i;
        }
    }
    return -1;
}
//we will make iterator template for searching in diff value

template<class ForwardIterator,class T>
ForwardIterator search(ForwardIterator start,ForwardIterator end, T key){

   while(start!=end){
      if(*start == key) {
          return start;
      }
      start++;
   } 
   return end;
}

int main(){
    int arr[]= {1,5,3,8,12,6,};
    int n = sizeof(arr)/sizeof(int);
    int key = 12;
   // cout<<Search(arr,n,key);

    double d[] = {1.12,2.14,6.1,2.25};
   // cout<<Search(d,4,6.1);

 // So here two type of data types working on one Function


  list<int> l;
  l.push_back(1);
  l.push_back(3);
  l.push_back(7);
  l.push_back(9);
  l.push_back(10);

  auto it =search(l.begin(),l.end(),15);
  if(it==l.end()){
     cout<<"not present";
  }
   else   cout<<*it;;

    return 0;
}