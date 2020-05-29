/*
  Heap sort Tn = O(nlogn)
  we have unsorted array.

  |4|3|7|1|8|5|
  while searching for minimum element we are applying linear search.
  But optimised --->using heaps 
  1. Build heap from array
   down heapify
   8 4 7 1 3 5

   down heafify -> swap(root,last_ele)
   so in simple linear search O(1) and removal in O(logn) 
   it is inplace sorting
   S(n) =O(logn) 

   pseudo code
   void heapsort(*arr,n){
     heap_size =n;
     build heap(arr,n)
     for(i=n;i>=2;i--){
        swap(root,last_ele)
        heap_size -= 1;
        downheapify();
     }
   }
   But compare to other sorting it is not that stable.

*/

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
*/
void heapFrom_array(vector<int> &heap)
{ //O(nlog n)
    for (int i = 0; i < heap.size(); i++)
    {
        upheapify(heap, i);
    }
}
/*
It is a optimised way to create a heap from array
      O(n)  complexity
      by using down heapification. 
*/
void heapFrom_array_optimised(vector<int> &heap)
{
    for (int i = heap.size() - 1; i >= 0; i--)
    {
        down_heapify(heap, i);
    }
}
//heapsort
void down_heapify_heapHelper(vector<int> &heap, int idx,int heapSize)
{
    int leftchild = 2 * idx + 1;
    int rightchild = 2 * idx + 2;
    if (leftchild >= heapSize and rightchild >= heapSize)
    {
        return;
    }
    int largestIdx = idx;
    if (leftchild < heapSize and heap[leftchild] > heap[largestIdx])
    {
        largestIdx = leftchild;
    }
    if (rightchild < heapSize and heap[rightchild] > heap[largestIdx])
    {
        largestIdx = rightchild;
    }

    if (largestIdx == idx)
    {
        return;
    }
    swap(heap[idx], heap[largestIdx]);
    down_heapify_heapHelper(heap, largestIdx,heapSize);
}
void heapsort(vector<int> &arr)  //O(nlogn)
{
    int heapSize = arr.size();
    heapFrom_array_optimised(arr);
    for(int i=arr.size()-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapSize-=1;
        down_heapify_heapHelper(arr,0,heapSize);
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
    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(arr, x);
    }
    //heapFrom_array( arr);
    heapFrom_array_optimised(arr);
    heapsort(arr);

    display(arr);

    return 0;
}