#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

int main(){
  
    pair<int,char> p1;
    p1.first =10;
    p1.second='s';

    cout<<p1.first<<endl;
    cout<<p1.second<<endl;
    
    cout<<"------------------------"<<endl;
    //another way
    pair<int, char> p2(p1);
    cout << p2.first << endl;
    cout << p2.second << endl;

    //make pair
    pair<int,string> p3=make_pair(31,"Saurav");
    cout<<p3.first <<" and "<<p3.second<<endl;


    cout<<"give two input(int)"<<endl;
    //taking input
    int a,b;
    cin>>a>>b;
    pair<int,int> p4=make_pair(a,b);
     //array of pairs
     //vectors of pairs

     pair<pair<int,int>, string> car;      //  , is very imp to categorize 
     car.second ="saurav's car";
     car.first.first =5230;
     car.first.second =7054;

     cout << car.second<<endl;
     cout << car.first.first << endl ;
     cout << car.first.second<<endl;


 return 0;
}
