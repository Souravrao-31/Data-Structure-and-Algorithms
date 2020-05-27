#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


void Vector(){
    //STANDARD TEMPLATE LIBRARY

    vector<int> A = {1, 11, 2, 20, 15};
    cout << A[1] << endl; //11

    sort(A.begin(), A.end()); //O(NLogN)

    //binary search
    bool present = binary_search(A.begin(), A.end(), 2); // TRUE O(LogN)
    present = binary_search(A.begin(), A.end(), 10);     //False

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100);

    // 1,2,11,15,20,100

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);

    // 1,2,11,15,20,100,100,100,100

    A.push_back(123);
    // 1,2,11,15,20,100,100,100,100,123

    vector<int>::iterator lb = lower_bound(A.begin(), A.end(), 100); //>=
    vector<int>::iterator ub = upper_bound(A.begin(), A.end(), 100); //>

    /*  or  instead of vector we can use auto */

    auto lb1c = lower_bound(A.begin(), A.end(), 100);
    auto ub1 = upper_bound(A.begin(), A.end(), 100);

    cout << *lb << " " << *ub << endl;
    cout << abs(lb - ub) << endl; //how many times 100 occurs

    for (int &x : A)
    {
        x++; //one is incremented in array
    }
    for (int x : A)
    {
        cout << x << " "; //2 3 12 16 21 101 101 101 101 124
    }
}


void setdemo(){

 /* in Set we does'nt need to sort array it will sort the array automatically*/
 set<int> S;
 S.insert(1);
 S.insert(2);
 S.insert(-1);
 S.insert(-10);
 for(int x:S){
     cout<<x<<" ";
 }
   cout<<endl;

 auto it=S.find(-1);
 if (it==S.end()){
     cout<<"not present"<<endl;
 }
 else{
     cout<<*it<<endl;
 }

 auto it2=S.upper_bound(-1);
 auto it3=S.lower_bound(0);
 cout<<*it2<<" "<<*it3<<endl;

 auto it4=S.upper_bound(2);
 if(it4==S.end){
     cout<<"oops sorry can't find any thing like this"<<endl;
 }

}

void mapdemo(){
//O(Logn)

map<int int> A;
A[1] =100;
A[2] =-1;
A[3] =200;
A[100003556] = 10;

map<char,int> cnt;
string x="Sourav rao";

for(char c : x){
    cnt[c]++;
}

cout<<cnt['a']<<" "<<cnt['z']<<end;

}


int main(){
    //Vector();
      mapdemo();
    //setdemo();
    return 0;
}