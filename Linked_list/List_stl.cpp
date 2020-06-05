#include<iostream>
#include<list>  //insert and del in middle head and tail, it is very useful
using namespace std;

int main(){
    list<int> l;
    //init
    list<int> l1{1,2,3,4,10,20};
    // Different datatype
    list<string> l2{"apple","guava","mango","banana"};
    l2.push_back("Litchi");  //add element in  the list
    
    //pop_front
    cout<<l2.front()<<endl;
    l2.pop_front();


    //add front to the list
    l2.push_front("kiwi");
    cout<<l2.back()<<endl;
    l2.pop_back();

    //Sort
    l2.sort();

    l1.reverse();

    //Iterate over the list

    for(auto it =l2.begin();it!=l2.end();it++){
        cout<<(*it)<<" ->";
    }
    cout<<endl;

    for(string s:l2){
       cout<<s<<"-->";
    }
    cout<<endl;

    //some more function in the list
   
    l2.push_back("lemon");
    l2.push_back("guava");
    for (string s : l2)
    {
        cout << s << "-->";
    }
    cout<<endl;
    //remove a fruit
    string f;
    cin>>f;
    l2.remove(f);
    for (string s : l2)
    {
        cout << s << "-->";
    }
    cout << endl;


    

    return 0;
}