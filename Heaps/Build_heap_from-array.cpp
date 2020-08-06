#include <iostream>
#include <vector>
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

void upheapify(vector<int> &heap, int idx)
{ //pass by reference
    //O(log n)
    if (idx == 0)
    {
        return;
    }
    //upheafication process.
    int parentIdx = (idx - 1) / 2;
    if (heap[parentIdx] < heap[idx])
    {
        //swap
        int temp = heap[parentIdx];
        heap[parentIdx] = heap[idx];
        heap[idx] = temp;
        upheapify(heap, parentIdx); //Reccursively grow towards root
    }
    else
    {
        return;
    }
}
void down_heapify(vector<int> &heap, int idx)
{
    int leftchild = 2 * idx + 1;
    int rightchild = 2 * idx + 2;
    if (leftchild >= heap.size() and rightchild >= heap.size())
    {
        return;
    }
    int largestIdx = idx;
    if (leftchild < heap.size() and heap[leftchild] > heap[largestIdx])
    {
        largestIdx = leftchild;
    }
    if (rightchild < heap.size() and heap[rightchild] > heap[largestIdx])
    {
        largestIdx = rightchild;
    }

    if (largestIdx == idx)
    {
        return;
    }
    swap(heap[idx], heap[largestIdx]);
    down_heapify(heap, largestIdx);
}
void insert(vector<int> &heap, int key)
{
    heap.push_back(key);
    upheapify(heap, heap.size() - 1);
}
/*
 building heap from unsorted array 
 O(nlog n)
*/
void heapFrom_array(vector<int> &heap){ 
    for(int i=0;i<heap.size();i++){
        upheapify(heap,i);
    }
}
/*
It is a optimised way to create a heap from array
      O(n)  complexity
      by using down heapification. 
*/
void heapFrom_array_optimised(vector<int> &heap)
{
    for(int i=heap.size() - 1;i >= 0;i--){
        down_heapify(heap,i);
    }
}

void display(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> heap;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(heap, x);
        
    }
    //heapFrom_array(heap);
    heapFrom_array_optimised(heap);
    
    display(heap);

    return 0;
}