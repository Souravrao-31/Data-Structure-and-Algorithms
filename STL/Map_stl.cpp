#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,int> m;

    //Insert
    m.insert(make_pair("Maggi",80));
    m.insert(make_pair("Fries", 60));
    //Insert 2.0
    pair<string,int> p;
    p.first="Apple";
    p.second=120;

    m.insert(p);
    m["banana"] =20;

    //Search
    string fruit;
    cin>>fruit;

    //We can also update
    m[fruit] +=20;
    m["litchi"] = 60;
    m["pineapple"] = 80;



    auto it = m.find(fruit);
    if(it != m.end()){
       cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }


    //erase
    m.erase(fruit);
    //Another wayy to find a particular map
    //It stores unique keys only once
    if(m.count(fruit)){  //returns int
        cout<<"Price is  "<<m[fruit]<<endl;
    }
    else{
        cout<<"Couldn't Find "<<endl;
    }

    //Iterate over all the key value pairs 1.0
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }
    //for each loop 2.0
    for(auto p:m){
       cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}