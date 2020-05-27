#include<iostream>
#include<set>
#include<climits>
using namespace std;
/*
Multiset that can store multiple elements that have same elements
sorted in aspecefic  -> sorted according to internal comparison object
values once inserted can't be modified
associative container -> elements are refered by their value and not by the index. 
underlying data structure  = BST
*/
typedef multiset<int>::iterator It;
int main(){
    int arr[] ={10,20,11,14,20,15,1,7,20,15,10,12,20};
    int n = sizeof(arr)/sizeof(int);

    multiset<int> m(arr,arr+n);

    //iterative 
     m.erase(10);  //erase

     m.insert(50);
    for(int x:m){
      cout<<x<<" "; //not unique value
    }
   //count
   cout<<"Count"<<m.count(20)<<endl;

   //find
   auto it = m.find(20);
   cout<<(*it)<<endl;

   //get all elements which are equal to 20
   pair<It,It> range= m.equal_range(20);
   for(auto it = range.first;it != range.second; it++){
      cout<<*it<<"--";
   }
   cout<<endl;
   //Lower >= upper bound

   for(auto it=m.lower_bound(10); it != m.upper_bound(50);it++){
      cout<<*it<<"->";
   }


   return 0;
}
