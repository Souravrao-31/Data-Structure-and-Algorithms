#include<iostream>
#include<vector>
using namespace std;
/*
Heaps 
if vector starts from 1;
   left child = 2*i
   right child =2*i+1
   parent = i/2

   if vector starts from 0;
   left child = 2*i+1
   right child =2*i+2
   parent = (i-1)/2

*/

void upheapify(vector<int> &heap,int idx){  //pass by reference
    //O(log n)
    if(idx == 0){
       return;
    }
    //upheafication process.
    int parentIdx =(idx-1)/2;
    if(heap[parentIdx] < heap[idx]){
       //swap
       int temp = heap[parentIdx];
       heap[parentIdx]=heap[idx];
       heap[idx] = temp;
       upheapify(heap,parentIdx); //Reccursively grow towards root
    }
    else{
        return;
    }


}

void insert(vector<int> &heap,int key){
    heap.push_back(key);
    upheapify(heap, heap.size()-1);
}
void display(vector<int> &heap){
   for(int i=0;i<heap.size();i++){
       cout<<heap[i]<<" ";
   }
   cout<<endl;
}

int main(int argc,char const *argv[]){
    vector<int> heap;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
       int x;
       cin>>x;
       insert(heap,x);
    }
    display(heap);

    
    return 0;
}